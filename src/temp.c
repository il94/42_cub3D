/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:23:26 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/18 22:33:23 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	put_vertical_line(t_game *game, int y_start)
{
	int	y;
	int	y_end;

	y = game->player.px.y;
	y_end = game->ray.px.y;
	while ((y != y_end))
	{
		put_pixel(&game->trimmed_minimap, game->player.px.x, y, RED);
		if (y_start > y_end)
			y--;
		else
			y++;
	}
}

void	put_line(t_game *game, t_fpos start, t_fpos end, double coeff)
{
	t_pos	pos;
	double	error;

	pos.x = start.x;
	pos.y = start.y;
	error = 0;
	while (pos.x <= end.x)
	{
		put_pixel(&game->trimmed_minimap, pos.x, pos.y, RED);
		error -= coeff;
		while (error < -0.5)
		{
			if (pos.x < end.x)
				put_pixel(&game->trimmed_minimap, pos.x, pos.y, RED);
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
	t_fpos	start;
	t_fpos	end;
	t_fpos	pos;

	start.x = game->player.px.x;
	start.y = game->player.px.y;
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

void	put_raycasting_minimap(t_game *game, float angle, t_fpos ray)
{
	t_fpos	start;
	t_fpos	end;
	t_fpos	pos;

	t_fpos	tmp1 = game->player.px;

	tmp1.x = (TMP * game->player.px.x / TILE);
	tmp1.y = (TMP * game->player.px.y / TILE);

	t_fpos	tmp2 = game->player.px;

	tmp2.x = (TMP * ray.x / TILE);
	tmp2.y = (TMP * ray.y / TILE);


	start.x = TMP_MAP / 2;
	start.y = TMP_MAP / 2;
	end.x = TMP_MAP / 2 + (cos(angle) * hypotenus(tmp1, tmp2));
	end.y = TMP_MAP / 2 + (-sin(angle) * hypotenus(tmp1, tmp2));
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

void	put_point(t_game *game, int x, int y, int color)
{
	int	x_index;
	int	y_index;

	x_index = x - (POINT / 2);
	while (x_index < x + (POINT / 2))
	{
		y_index = y - (POINT / 2);
		while (y_index < y + (POINT / 2))
		{
			put_pixel(&game->trimmed_minimap, x_index, y_index, color);
			y_index++;
		}
		x_index++;
	}
}

void	print_ray(t_ray ray)
{
	printf(" \
	PX\nx = %f | y = %f\n\n \
	OFF H\nx = %f | y = %f\n\n \
	OFF V\nx = %f | y = %f\n\n \
	ANGLE = %f\n================\n", \
		ray.px.x, ray.px.y, \
		ray.offset_h.x, ray.offset_h.y, \
		ray.offset_v.x, ray.offset_v.y, \
		ray.angle);
}