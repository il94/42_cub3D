/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/09 17:00:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_tile(t_img *minimap, int color, int x, int y)
{
	int	x_tile;
	int	y_tile;

	y_tile = 0;
	while (y_tile < 48)
	{
		x_tile = 0;
		while (x_tile < 48)
		{
			if (x_tile < 1 || x_tile > 47 || y_tile < 1 || y_tile > 47)
				my_mlx_pixel_put(minimap, x + x_tile, y + y_tile, BLACK);
			else
				my_mlx_pixel_put(minimap, x + x_tile, y + y_tile, color);
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
				draw_tile(&game->minimap, WHITE, x * 48, y * 48);
			else if (game->map[y][x] == '1')
				draw_tile(&game->minimap, GREY, x * 48, y * 48);
			else
				draw_tile(&game->minimap, GREY, x * 48, y * 48);			
			x++;
		}
		y++;
	}
}

void	put_render(t_game *game)
{
	put_minimap(game);
	// my_mlx_pixel_put(&game->minimap, 5, 5, PURPLE);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->minimap.img, 0, 0);
}