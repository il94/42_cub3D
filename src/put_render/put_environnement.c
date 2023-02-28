/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_environnement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:35:10 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/28 19:09:22 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_fpos	get_vertical_collision(t_game *game, t_fpos start)
{
	t_fpos	point;

	point = start;
	while (!is_vertical_wall(game->map, point, !game->ray.left))
	{
		if (game->ray.up)
			point.y -= game->ray.offset_v.y;
		else
			point.y += game->ray.offset_v.y;
		if (game->ray.left)
			point.x -= game->ray.offset_v.x;
		else
			point.x += game->ray.offset_v.x;
	}
	return (point);
}

static t_fpos	get_horizontal_collision(t_game *game, t_fpos start)
{
	t_fpos	point;

	point = start;
	while (!is_horizontal_wall(game->map, point, !game->ray.up))
	{
		if (game->ray.up)
			point.y -= game->ray.offset_h.y;
		else
			point.y += game->ray.offset_h.y;
		if (game->ray.left)
			point.x -= game->ray.offset_h.x;
		else
			point.x += game->ray.offset_h.x;
	}
	return (point);
}

static t_fpos	get_collision(t_game *game, t_fpos start_h, t_fpos start_v)
{
	t_fpos	result_h;
	t_fpos	result_v;
	float	distance_h;
	float	distance_v;

	result_h = get_horizontal_collision(game, start_h);
	result_v = get_vertical_collision(game, start_v);
	distance_h = hypotenus(game->player.px, result_h);
	distance_v = hypotenus(game->player.px, result_v);
	if (distance_h <= distance_v)
	{
		// printf("res = %f | res = %f\n", result_h.x, result_h.y);
		if (game->map[(int)result_h.y / TILE - 1 + !game->ray.up][(int)result_h.x / TILE] == '2')
			game->ray.door = TRUE;
		else
			game->ray.door = FALSE;
		game->ray.wall_v = FALSE;
		game->ray.wall_h = TRUE;
		return (result_h);
	}
	else
	{
		if (game->map[(int)result_v.y / TILE][(int)result_v.x / TILE - 1 + !game->ray.left] == '2')
			game->ray.door = TRUE;
		else
			game->ray.door = FALSE;
		game->ray.wall_h = FALSE;
		game->ray.wall_v = TRUE;
		return (result_v);
	}
}

static void	catch_special_ray(t_game *game, int i)
{
	if (i == 0)
		game->ray1 = game->ray;
	else if (i == WIDTH - 1)
		game->ray2 = game->ray;
	else if (i == WIDTH / 2)
		game->ray3 = game->ray;
}

void	put_environnement(t_game *game)
{
	t_fpos	start_h;
	t_fpos	start_v;
	float	ray_dist;
	int		i;

	game->ray.angle = correc_angle(game->player.angle + to_rad(FOV / 2));
	i = 0;
	while (i < WIDTH)
	{
		game->ray.up = (game->ray.angle >= PI_0 && game->ray.angle < M_PI);
		game->ray.left = (game->ray.angle >= PI_90 && game->ray.angle < PI_270);
		start_h = init_start_h(game);
		start_v = init_start_v(game);
		init_offset(game);
		game->ray.px = get_collision(game, start_h, start_v);
		catch_special_ray(game, i);
		ray_dist = hypotenus(game->player.px, game->ray.px);
		ray_dist *= cos(game->player.angle - game->ray.angle);
		ray_dist = fabs(TILE / ray_dist * HEIGHT);
		put_column_anim(game, get_image(game), ray_dist, i);
		// if (game->ray.door)
		// 	put_column(game, &game->door, ray_dist, i);
		game->ray.angle = correc_angle(game->ray.angle - to_rad(FOV) / WIDTH);
		i++;
	}
	put_image(&game->render, &game->environnement, 0, 0);
}
