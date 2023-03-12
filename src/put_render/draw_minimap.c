/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:55:20 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/11 22:56:40 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	put_image_tile(t_game *game, int color, int x, int y)
{
	int	x_tile;
	int	y_tile;

	x = x * MNMP_TILE;
	y = y * MNMP_TILE;
	y_tile = 0;
	while (y_tile < MNMP_TILE)
	{
		x_tile = 0;
		while (x_tile < MNMP_TILE)
		{
			if (x_tile < 1 || x_tile > MNMP_TILE - 1
				|| y_tile < 1 || y_tile > MNMP_TILE - 1
				|| x + x_tile == game->size_map.x - 1
				|| y + y_tile == game->size_map.y - 1)
				put_pixel(&game->full_minimap, x + x_tile, y + y_tile, BLACK);
			else
				put_pixel(&game->full_minimap, x + x_tile, y + y_tile, color);
			x_tile++;
		}
		y_tile++;
	}
}

void	draw_minimap(t_game *game)
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
				put_image_tile(game, game->f_color, x, y);
			else
				put_image_tile(game, game->f_color << 1, x, y);
			x++;
		}
		y++;
	}
}
