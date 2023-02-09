/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/09 20:11:48 by adouay           ###   ########.fr       */
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
	int	x_tile = 25;
	int	y_tile = 25;
	// int	y_tile;
	// dir = 0;
	if (game->move_up)
	{
		while (y_tile + game->player.y >= game->player.dir_y)
		{
			my_mlx_pixel_put(&game->minimap, game->player.x + 25, y_tile + game->player.y, BLACK);
			y_tile--;
		}
	}
	if (game->move_right)
	{
		while (y_tile + game->player.y >= game->player.dir_y)
		{
			my_mlx_pixel_put(&game->minimap, game->player.x + 25, y_tile + game->player.y, BLACK);
			y_tile--;
		}
	}
	if (game->move_down)
	{
		y_tile = 50;
		while (game->player.y - y_tile <= game->player.dir_y)
		{
			my_mlx_pixel_put(&game->minimap, game->player.x + 25, game->player.y + y_tile, BLACK);
			y_tile--;
		}
	}
	if (game->move_left)
	{
		while (y_tile + game->player.y >= game->player.dir_y)
		{
			my_mlx_pixel_put(&game->minimap, game->player.x + 25, y_tile + game->player.y, BLACK);
			y_tile--;
		}
	}
	// 	game->player.y -= 5;
	// if (game->move_right)
	// 	game->player.x += 5;
	// if (game->move_down)
	// 	game->player.y += 5;
	// if (game->move_left)
	// 	game->player.x -= 5;
	// while ()
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
	draw_player(game, PURPLE, game->player.x, game->player.y);
}

void	put_render(t_game *game)
{
	put_minimap(game);
	// my_mlx_pixel_put(&game->minimap, 5, 5, PURPLE);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->minimap.img, 0, 0);
}