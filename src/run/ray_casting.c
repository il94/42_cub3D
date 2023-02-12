/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:01:12 by adouay            #+#    #+#             */
/*   Updated: 2023/02/12 23:22:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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

static void	print_ray(t_ray ray, t_fpos first)
{
	printf("PX\nx = %f | y = %f\n\nOFF H\nx = %f | y = %f\n\nOFF V\nx = %f | y = %f\n\n F POS\nx = %f | y = %f\n\nANGLE = %f\n================\n", ray.px.x, ray.px.y, ray.offset_h.x, ray.offset_h.y, ray.offset_v.x, ray.offset_v.y, first.x, first.y, ray.angle);
}

// static int	find_wall(t_game *game, t_bool up, t_bool left)
// {
// 	t_pos	pos;
// 	int		i;
	
// 	pos.x = game->player.map_x;
// 	pos.y = game->player.map_y;
	
// 	i = 0;
// 	if (up)
// 	{
// 		while (game->map[pos.y][pos.x] != '1')
// 		{
			
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (game->map[pos.y][pos.x] != '1')
// 			i++;
// 	}
// 	return (i);
// }

void	ray_casting(t_game *game)
{
	// game->player.map_x = 6;
	// game->player.map_y = 3;
	game->player.px_x = 317;
	game->player.px_y = 170;
	game->player.angle = 1.894395;
	game->ray.angle = 1.894395;

	t_bool	to_up;
	t_bool	to_left;
	t_fpos	pos;
	t_fpos	first_pos;

	first_pos.x = 0;
	first_pos.y = 0;
	// game->ray.angle = game->player.angle;

	to_up = FALSE;
	if (game->ray.angle >= PI_0 && game->ray.angle < M_PI)
		to_up = TRUE;
	to_left = FALSE;
	if (game->ray.angle >= PI_90 && game->ray.angle < PI_270)
		to_left = TRUE;


	if (to_up)
	{
		printf("To up\n");
		pos.y = game->player.px_y - (game->player.map_y * TILE);
	}
	else
	{
		printf("To down\n");
		pos.y = (game->player.map_y * TILE + TILE) - game->player.px_y;
	}
	if (to_left)
	{
		printf("To left\n\n");
		pos.x = game->player.px_x - (game->player.map_x * TILE);
	}
	else
	{
		printf("To right\n\n");
		pos.x = (game->player.map_x * TILE + TILE) - game->player.px_x;
	}

	if (to_up && to_left) //1er cas
	{
		game->ray.offset_h.x = TILE;
		game->ray.offset_v.y = TILE;

		first_pos.x = game->player.px_x - pos.y / -tan(game->ray.angle) ;
		first_pos.y = game->player.px_y - pos.y;

		// game->ray.offset_h.y = ?;
		// game->ray.offset_v.x = ?;
	}

	
	
	printf("POS MAP = %d %d\n", game->player.map_x, game->player.map_y);
	printf("POS  PX = %f %f\n\n", game->player.px_x, game->player.px_y);
	printf("POS TMP = %f %f\n\n", pos.x, pos.y);
	print_ray(game->ray, first_pos);

	
	
}