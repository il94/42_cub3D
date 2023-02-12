/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:01:12 by adouay            #+#    #+#             */
/*   Updated: 2023/02/12 12:41:30 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	check_inter(t_game *game, int i, int j)
{	
	if (game->map[i][j] && (game->map[i][j] == '0'))
		return (1);
	return (0);
}


int	check_wall(t_game *game, int i, int j)
{
	if (i > ft_get_size_array(game->map) || i < 0)
	{
		printf("IF 1 YOPOLOP\n");
		return (1);
	}
	if (j > ft_strlen(game->map[i]))
	{
		printf("IF 2 YOPOLOP\n");
		return (1);
	}
	if (game->map[i][j] && (game->map[i][j] == '1' || game->map[i][j] == '\0'))
	{
		printf("I = %d | J = %d\n", i, j);
		printf("IF 3 YOPOLOP\n");
		return (1);
	}
	else
	{
		printf("I = %d | J = %d\n", i, j);
		printf("SALUT\n");

	}
	return (0);
}

static void	put_point(t_game *game, int x, int y, int color)
{
	int	x_index;
	int	y_index;

	x_index = x - (POINT / 2);
	while (x_index < x + (POINT / 2))
	{
		y_index = y - (POINT / 2);
		while (y_index < y + (POINT / 2))
		{
			put_pixel(&game->minimap, x_index, y_index, color);
			y_index++;
		}
		x_index++;
	}
}

void	hit_dat_wall(t_game *game, int y, int x, int facing)
{
	int	i = 0;
	while (game->ray.x >= 0 && game->ray.x <= WIDTH && game->ray.y >= 0 && game->ray.y <= HEIGHT)
	{
		put_point(game, game->ray.x, game->ray.y, GREEN);
		if (check_wall(game, y, x))
			break ;
		game->ray.x += game->ray.offset_x;
		game->ray.y += game->ray.offset_y;
		// if (check_inter(game, y, x))
		{
			if (facing)
				y--;
			else
				y++;	
		}
	}
	if (game->ray.x >= 0 && game->ray.x <= WIDTH && game->ray.y >= 0 && game->ray.y <= HEIGHT)
		put_point(game, game->ray.x, game->ray.y, RED);
}

void	hit_dat_wall2(t_game *game, int y, int x, int facing)
{
	int	i = 0;
	while (game->ray2.x >= 0 && game->ray2.x <= WIDTH && game->ray2.y >= 0 && game->ray2.y <= HEIGHT)
	{
		printf("I = %d\n", i);
		i++;
		put_point(game, game->ray2.x, game->ray2.y, GREEN);
		if (check_wall(game, y, x))
			break ;
		game->ray2.x += game->ray2.offset_x;
		game->ray2.y += game->ray2.offset_y;
		// if (check_inter(game, y, x))
		{
			if (facing)
				x++;
			else
				x--;	
		}
	}
	if (game->ray2.x >= 0 && game->ray2.x <= WIDTH && game->ray2.y >= 0 && game->ray2.y <= HEIGHT)
		put_point(game, game->ray2.x, game->ray2.y, RED);
}

void	cast_ray_v(t_game *game)
{
	/* VERTICAL */
	int	facing_up;
	int	facing_down;
	
	facing_up = 0;
	game->ray2.angle = -(game->player.angle);
	if (game->ray2.angle > 0 && game->ray2.angle < M_PI)
		facing_up = 1;
	facing_down = !facing_up;

	game->ray2.x = (int)(game->player.px_x / TILE) * TILE; // facing_right
	game->ray2.offset_x = -TILE;
	if (game->ray2.angle > 3 * M_PI / 2)
	{
		game->ray2.x += TILE;	
		game->ray2.offset_x *= -1;
	}
	if (game->ray2.angle == 3 * M_PI / 2 || game->ray2.angle == M_PI / 2)
	{
		game->ray2.x = game->player.px_y;
		game->ray2.y = game->player.px_x;
		return ; 
	}
	game->ray2.y = game->player.px_y + ((game->player.px_x - game->ray2.x) / tan(game->ray2.angle));
	game->ray2.offset_y = TILE / tan(game->ray2.angle);
	if (game->ray2.offset_y > 0 && facing_up) //up
		game->ray2.offset_y *= -1;
	if (game->ray2.offset_y < 0 && facing_down)//down
		game->ray2.offset_y *= -1;

	
	// printf("nearest x hit : %f\n", game->ray2.x);
	// printf("nearest y hit : %f\n", game->ray2.y);
		
	// printf("offset x hit : %f\n", game->ray2.offset_x);
	// printf("offset y hit : %f\n", game->ray2.offset_y);

	// printf("player x: %f\n", game->player.px_x);
	// printf("player y: %f\n", game->player.px_y);

	//printf("angle: %f\n", game->ray2.angle);
	if (facing_up)
		hit_dat_wall2(game, (int)(game->ray2.y / TILE), (int)(game->ray2.x / TILE) + 1, 0);
	else
		hit_dat_wall2(game, (int)(game->ray2.y / TILE), (int)(game->ray2.x / TILE), 1);
}

void	cast_ray_h(t_game *game)
{
	/* HORIZONTAL */
	int	facing_left;
	int	facing_right;

	facing_left = 0;
	game->ray.angle = game->player.angle;
	if (game->ray.angle > 0.5 * M_PI && game->ray.angle < 1.5 * M_PI)
		facing_left = 1;
	facing_right = !facing_left;
	
	game->ray.y = (int)(game->player.px_y / TILE) * TILE; // if (game->ray.angle < M_PI)
	game->ray.offset_y = -TILE;
	if (game->ray.angle > M_PI)
	{
		game->ray.y += TILE;	
		game->ray.offset_y *= -1;
	}

	if (game->ray.angle == M_PI || game->ray.angle == 0)
	{
		game->ray.y = game->player.px_x;
		game->ray.x = game->player.px_y;
		return ; 
	}

	game->ray.x = game->player.px_x + ((game->player.px_y - game->ray.y) / tan(game->ray.angle));
	game->ray.offset_x = TILE / tan(game->ray.angle);
	if (game->ray.offset_x > 0 && facing_left)
		game->ray.offset_x *= -1;
	if (game->ray.offset_x < 0 && facing_right)
		game->ray.offset_x *= -1;


	//printf("angle: %f\n", game->ray.angle);
	if (game->ray.angle < M_PI)
		hit_dat_wall(game, (int)(game->ray.y / TILE) - 1, (int)(game->ray.x / TILE), 1);
	else
		hit_dat_wall(game, (int)(game->ray.y / TILE), (int)(game->ray.x / TILE), 0);
}
	// if (game->ray.angle == M_PI || game->ray.angle == 0) // pas sur de celle la
	// 	return ;
	// else if (game->ray.angle < M_PI)
	// {
	// 	game->ray.offset_x = TILE / tan(game->ray.angle);
	// 	game->ray.y = game->player.px_y - (int)(game->player.px_y / TILE) * TILE;
	// 	game->ray.x = game->ray.y / tan(game->ray.angle);
	// 	put_pixel(&game->minimap, (int)game->player.px_x + game->ray.x, (int)game->player.px_y - game->ray.y, PURPLE);
		
	// }
	// else if (game->ray.angle > M_PI)
	// {
	// 	game->ray.offset_x = TILE / tan(game->ray.angle);
	// 	game->ray.y = game->player.px_y - (int)(game->player.px_y / TILE) * TILE;
	// 	game->ray.x = game->ray.y / tan(game->ray.angle);
	// 	put_pixel(&game->minimap, (int)game->player.px_x + game->ray.x, (int)game->player.px_y - game->ray.y, PURPLE);
	// }