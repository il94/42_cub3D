/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/10 19:03:51 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_dir(t_game *game)
{
	
}

void	draw_player(t_game *game, int color, int x, int y)
{
	int	x_tile;
	int	y_tile;

	y_tile = 0;
	while (y_tile < 50)
	{
		x_tile = 0;
		while (x_tile < 50)
		{
			if (x_tile >= 21 && x_tile <= 29 && y_tile >= 21 && y_tile <= 29)
				my_mlx_pixel_put(&game->minimap, x + x_tile, y + y_tile, color);
			if (x_tile == 25 && y_tile ==25)
				my_mlx_pixel_put(&game->minimap, x + x_tile + (int) game->player.dir_x, y + y_tile + (int)game->player.dir_y, color);
			x_tile++;
		}
		y_tile++;
	}
	draw_dir(game);
}


void	draw_tile(t_game *game, int color, int x, int y)
{
	int	x_tile;
	int	y_tile;

	y_tile = 0;
	while (y_tile < 50)
	{
		x_tile = 0;
		while (x_tile < 50)
		{
			if (x_tile < 1 || x_tile > 49 || y_tile < 1 || y_tile > 49)
				my_mlx_pixel_put(&game->minimap, x + x_tile, y + y_tile, BLACK);
			else
				my_mlx_pixel_put(&game->minimap, x + x_tile, y + y_tile, color);
			x_tile++;
		}
		y_tile++;
	}
}

void	put_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || check_player_carac(game->map[y][x]))
				draw_tile(game, WHITE, x * 50, y * 50);
			else if (game->map[y][x] == '1')
				draw_tile(game, GREY, x * 50, y * 50);
			else
				draw_tile(game, BLACK, x * 50, y * 50);			
			x++;
		}
		y++;
	}
	draw_player(game, PURPLE, game->player.px_x, game->player.px_y);
}

void	cast_ray(t_game *game)
{
	float	atan;
	game->ray.angle = game->player.angle;
	atan = -1/tan(game->ray.angle);
	int	i;
	i = 0;
	/*	horizontal check*/
	if (game->ray.angle < M_PI) // looking up;
	{
		game->ray.y = game->player.px_y;
		game->ray.x = (game->player.px_y - game->ray.y) * atan + game->player.px_x;
		game->ray.offset_y = -50;
		game->ray.offset_x = -game->ray.offset_y * atan;
	}
	else if (game->ray.angle > M_PI) // looking down;
	{
		
		game->ray.y = game->player.px_y + 50;
		game->ray.x = (game->player.px_y - game->ray.y) * atan + game->player.px_x;
		game->ray.offset_y = 50;
		game->ray.offset_x = -game->ray.offset_y * atan;
	}
	else if (game->ray.angle == 0 || game->ray.angle == M_PI)
	{
		game->ray.x = game->player.px_x;
		game->ray.y = game->player.px_y;
		i = 20; // futur map_x; 
	}
	printf("ray x : %f\n", game->ray.x);
	printf("ray y : %f\n", game->ray.y);
	while ( i < 20) // futur max x;
	{
		game->ray.map_x = (int)game->ray.x / 50;
		game->ray.map_y = (int)game->ray.y / 50;
		if (game->map[game->ray.map_y][game->ray.map_x] && game->map[game->ray.map_y][game->ray.map_x] == '1') // segfault peut etre si map diforme, 
		{
			break; // hit wall
		}
		else
		{
			game->ray.x += game->ray.offset_x;
			game->ray.y += game->ray.offset_y;
			i++;
		}
	}
	my_mlx_pixel_put(&game->minimap, game->ray.x, game->ray.y, GREY);
}

void	put_render(t_game *game)
{
	put_minimap(game);
	cast_ray(game);
	// my_mlx_pixel_put(&game->minimap, 5, 5, PURPLE);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->minimap.img, 0, 0);
}