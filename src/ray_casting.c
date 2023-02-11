/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:01:12 by adouay            #+#    #+#             */
/*   Updated: 2023/02/11 21:23:28 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_wall(t_game *game, int i, int j)
{
	if (i > ft_get_size_array(game->map) || i < 0)
		return (1);
	if (j > ft_strlen(game->map[i]))
		return (1);
	if (game->map[i][j] && (game->map[i][j] == '1' || game->map[i][j] == '\0'))
		return (1);
	return (0);
}

void	hit_dat_wall(t_game *game, int y, int x)
{
	while (game->ray.x >= 0 && game->ray.x <= WIDTH && game->ray.y >= 0 && game->ray.y <= HEIGHT)
	{
		// printf("%f\n", game->ray.x);
		// printf("%f\n", game->ray.y);
		if (check_wall(game, y, x))
			break ;
		game->ray.x += game->ray.offset_x;
		game->ray.y += game->ray.offset_y;
	}
	if (game->ray.x >= 0 && game->ray.x <= WIDTH && game->ray.y >= 0 && game->ray.y <= HEIGHT)
		my_mlx_pixel_put(&game->minimap, game->ray.x, game->ray.y, PURPLE);
}
void	cast_ray_v(t_game *game)
{
	/* VERTICAL */
	int	facing_left;
	int	facing_right;
	int	facing_up;
	int	facing_down;
	
	game->ray.angle = game->player.angle;
	
	facing_left = 0;
	facing_up = 0;
	
	if (game->ray.angle > 0.5 * M_PI && game->ray.angle < 1.5 * M_PI)
		facing_left = 1;
	if (game->ray.angle > 0 && game->ray.angle < M_PI)
		facing_up = 1;
		
	facing_down = !facing_up;
	facing_right = !facing_left;
	
	game->ray.x = (int)(game->player.px_x / 50) * 50; // facing_right
	game->ray.offset_x = 50;
	if (facing_right)
	{
		game->ray.x += 50;	
		game->ray.offset_x *= -1;
	}
	if (game->ray.angle == M_PI || game->ray.angle == 0)
	{
		game->ray.y = game->player.px_x;
		game->ray.x = game->player.px_y;
		return ; 
	}
	game->ray.y = game->player.px_y + ((game->player.px_x - game->ray.x) / tan(game->ray.angle));
	game->ray.offset_x = 50 / tan(game->ray.angle);
	if (game->ray.offset_x > 0 && facing_up) //up
		game->ray.offset_x *= -1;
	if (game->ray.offset_x < 0 && facing_down)//down
		game->ray.offset_x *= -1;

	
	printf("nearest x hit : %f\n", game->ray.x);
	printf("nearest y hit : %f\n", game->ray.y);
		
	printf("offset x hit : %f\n", game->ray.offset_x);
	printf("offset y hit : %f\n", game->ray.offset_y);

	printf("player x: %f\n", game->player.px_x);
	printf("player y: %f\n", game->player.px_y);

	printf("angle: %f\n", game->ray.angle);
	if (facing_left)
		hit_dat_wall(game, (int)(game->ray.y / 50), (int)(game->ray.x / 50) - 1);
	else
		hit_dat_wall(game, (int)(game->ray.y / 50), (int)(game->ray.x / 50));
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
	game->ray.y = (int)(game->player.px_y / 50) * 50; // if (game->ray.angle < M_PI)
	game->ray.offset_y = -50;
	if (game->ray.angle > M_PI)
	{
		game->ray.y += 50;	
		game->ray.offset_y *= -1;
	}
	if (game->ray.angle == M_PI || game->ray.angle == 0)
	{
		game->ray.y = game->player.px_x;
		game->ray.x = game->player.px_y;
		return ; 
	}
	game->ray.x = game->player.px_x + ((game->player.px_y - game->ray.y) / tan(game->ray.angle));
	game->ray.offset_x = 50 / tan(game->ray.angle);
	if (game->ray.offset_x > 0 && facing_left)
		game->ray.offset_x *= -1;
	if (game->ray.offset_x < 0 && facing_right)
		game->ray.offset_x *= -1;

	
	// printf("nearest x hit : %f\n", game->ray.x);
	// printf("nearest y hit : %f\n", game->ray.y);
		
	// printf("offset x hit : %f\n", game->ray.offset_x);
	// printf("offset y hit : %f\n", game->ray.offset_y);

	// printf("player x: %f\n", game->player.px_x);
	// printf("player y: %f\n", game->player.px_y);

	// printf("angle: %f\n", game->ray.angle);
	if (game->ray.angle < M_PI)
		hit_dat_wall(game, (int)(game->ray.y / 50) - 1, (int)(game->ray.x / 50));
	else
		hit_dat_wall(game, (int)(game->ray.y / 50), (int)(game->ray.x / 50));
}
	// if (game->ray.angle == M_PI || game->ray.angle == 0) // pas sur de celle la
	// 	return ;
	// else if (game->ray.angle < M_PI)
	// {
	// 	game->ray.offset_x = 50 / tan(game->ray.angle);
	// 	game->ray.y = game->player.px_y - (int)(game->player.px_y / 50) * 50;
	// 	game->ray.x = game->ray.y / tan(game->ray.angle);
	// 	my_mlx_pixel_put(&game->minimap, (int)game->player.px_x + game->ray.x, (int)game->player.px_y - game->ray.y, PURPLE);
		
	// }
	// else if (game->ray.angle > M_PI)
	// {
	// 	game->ray.offset_x = 50 / tan(game->ray.angle);
	// 	game->ray.y = game->player.px_y - (int)(game->player.px_y / 50) * 50;
	// 	game->ray.x = game->ray.y / tan(game->ray.angle);
	// 	my_mlx_pixel_put(&game->minimap, (int)game->player.px_x + game->ray.x, (int)game->player.px_y - game->ray.y, PURPLE);
	// }