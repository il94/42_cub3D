/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:55:20 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/14 20:26:03 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	put_vertical_line(t_game *game, int y_start)
{
	int	y;
	int	y_end;

	y = game->player.px_y;
	y_end = game->ray.px.y;
	while ((y != y_end))
	{
		put_pixel(&game->minimap, game->player.px_x, y, RED);
		if (y_start > y_end)
			y--;
		else
			y++;
	}
}

static void	put_line(t_game *game, t_pos start, t_pos end, double coeff)
{
	t_pos	pos;
	double	error;

	pos.x = start.x;
	pos.y = start.y;
	error = 0;
	while (pos.x <= end.x)
	{
		put_pixel(&game->render, pos.x + TILE, pos.y + TILE, RED);
		error -= coeff;
		while (error < -0.5)
		{
			if (pos.x < end.x)
				put_pixel(&game->render, pos.x + TILE, pos.y + TILE, RED);
			if (start.y > end.y)
				pos.y--;
			else
				pos.y++;
			error += 1.0;
		}
		pos.x++;
	}
}

void	put_direction_line(t_game *game)
{
	t_pos	start;
	t_pos	end;
	t_pos	pos;

	start.x = game->player.px_x;
	start.y = game->player.px_y;
	end.x = game->ray.px.x;
	end.y = game->ray.px.y;
	if (start.x > end.x)
	{
		swap(&start.x, &end.x);
		swap(&start.y, &end.y);
	}
	pos.x = start.x;
	pos.y = start.y;
	if (start.x == end.x && pos.y != end.y)
		put_vertical_line(game, start.y);
	else
		put_line(game, start, end, get_coeff(end.y, start.y, end.x, start.x));
}

static void	put_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player.px_x - (PLAYER_MINIMAP / 2);
	while (x < game->player.px_x + (PLAYER_MINIMAP / 2))
	{
		y = game->player.px_y - (PLAYER_MINIMAP / 2);
		while (y < game->player.px_y + (PLAYER_MINIMAP / 2))
		{
			put_pixel(&game->minimap, x, y, PURPLE);
			y++;
		}
		x++;
	}
}

static void	put_image_tile(t_game *game, int color, int x, int y)
{
	int	x_tile;
	int	y_tile;

	x = x * TILE;
	y = y * TILE;
	y_tile = 0;
	while (y_tile < TILE)
	{
		x_tile = 0;
		while (x_tile < TILE)
		{
			if (x_tile < 1 || x_tile > TILE - 1
				|| y_tile < 1 || y_tile > TILE - 1)
				put_pixel(&game->minimap, x + x_tile, y + y_tile, BLACK);
			else
				put_pixel(&game->minimap, x + x_tile, y + y_tile, color);
			x_tile++;
		}
		y_tile++;
	}
}

void	put_raycasting(t_game *game, t_fpos ray)
{
	t_pos	start;
	t_pos	end;
	t_pos	pos;

	start.x = game->player.px_x;
	start.y = game->player.px_y;
	end.x = ray.x;
	end.y = ray.y;
	if (start.x > end.x)
	{
		swap(&start.x, &end.x);
		swap(&start.y, &end.y);
	}
	pos.x = start.x;
	pos.y = start.y;
	if (start.x == end.x && pos.y != end.y)
		put_vertical_line(game, start.y);
	else
		put_line(game, start, end, get_coeff(end.y, start.y, end.x, start.x));
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
				put_image_tile(game, WHITE, x, y);
			else if (game->map[y][x] == '1')
				put_image_tile(game, GREY, x, y);
			else
				put_image_tile(game, BLACK, x, y);
			x++;
		}
		y++;
	}
	put_player(game);
	put_raycasting(game, game->ray1);
	put_raycasting(game, game->ray2);
	put_image(&game->render, &game->minimap, TILE, TILE);
}
