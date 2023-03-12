/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:23:26 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/11 23:06:07 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	put_column_color(t_game *game, int n)
{
	float	ray_dist;
	float	size_column;
	int		middle;
	int		i;

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
