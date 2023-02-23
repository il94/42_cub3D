/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:23:26 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/24 00:04:05 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	put_column_color(t_game *game, int n)
{
	float	ray_dist;
	float	size_column;
	int		middle;
	int		i;
	int	color;

	ray_dist = hypotenus(game->player.px, game->ray.px) * cos(game->player.angle - game->ray.angle);
	ray_dist = fabs(TILE / ray_dist * HEIGHT);
	size_column = ray_dist / 2;
	middle = HEIGHT / 2;
	i = 0;

	while(i < HEIGHT)
	{
		if (i < size_column && i >= size_column - 3)
		{
			put_pixel(&game->environnement, n, middle - i, BLACK);
			put_pixel(&game->environnement, n, middle + i, BLACK);
		}
		else if (i < size_column)
		{
			if (game->ray.wall_h)
			{
				put_pixel(&game->environnement, n, middle - i, BROWN);
				put_pixel(&game->environnement, n, middle + i, BROWN);
			}
			else
			{
				put_pixel(&game->environnement, n, middle - i, D_BROWN);
				put_pixel(&game->environnement, n, middle + i, D_BROWN);
			}
		}
		else
		{
			put_pixel(&game->environnement, n, middle - i, BLUE);
			put_pixel(&game->environnement, n, middle + i, GREEN);
		}
		i++;
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
		put_pixel(&game->minimap, pos.x, pos.y, RED);
		error -= coeff;
		while (error < -0.5)
		{
			if (pos.x < end.x)
				put_pixel(&game->minimap, pos.x, pos.y, RED);
			if (start.y > end.y)
				pos.y--;
			else
				pos.y++;
			error += 1.0;
		}
		pos.x++;
	}
}

void	put_minimap_ray(t_game *game, float angle, t_fpos ray)
{
	t_fpos	start;
	t_fpos	end;
	t_fpos	pos;

	t_fpos	tmp1 = game->player.px;

	tmp1.x = (MNMP_TILE * game->player.px.x / TILE);
	tmp1.y = (MNMP_TILE * game->player.px.y / TILE);

	t_fpos	tmp2 = game->player.px;

	tmp2.x = (MNMP_TILE * ray.x / TILE);
	tmp2.y = (MNMP_TILE * ray.y / TILE);


	start.x = MINIMAP / 2;
	start.y = MINIMAP / 2;
	end.x = MINIMAP / 2 + (cos(angle) * hypotenus(tmp1, tmp2));
	end.y = MINIMAP / 2 + (-sin(angle) * hypotenus(tmp1, tmp2));
	if (start.x > end.x)
	{
		swap(&start.x, &end.x);
		swap(&start.y, &end.y);
	}
	pos.x = start.x;
	pos.y = start.y;
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
			put_pixel(&game->minimap, x_index, y_index, color);
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