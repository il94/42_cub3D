/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_environnement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:35:10 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/16 04:21:50 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_bool	is_vertical_wall(char **map, t_fpos src, t_bool to_right)
{
	t_pos	pos;

	pos.x = src.x / TILE - 1 + to_right;
	pos.y = src.y / TILE;

	if (pos.y < 0 || pos.y >= ft_get_size_array(map))
		return (1);
	return (pos.x < 0 || pos.x > ft_strlen(map[pos.y]) || map[pos.y][pos.x] == '1');
}

static t_bool	is_horizontal_wall(char **map, t_fpos src, t_bool to_down)
{
	t_pos	pos;

	pos.x = src.x / TILE;
	pos.y = src.y / TILE - 1 + to_down;
	if (pos.y < 0 || pos.y >= ft_get_size_array(map))
		return (1);
	if (pos.x < 0 || pos.x >= ft_strlen(map[pos.y]))
		return (1);
	if (map[pos.y][pos.x] == '1')
		return (1);
	return (0);
}

static t_fpos	get_vertical_collision(t_game *game, t_fpos start)
{
	t_fpos	point;

	point = start;
	while (!is_vertical_wall(game->map, point, !game->ray.to_left))
	{
		// put_point(game, point.x, point.y, GREEN);
		if (game->ray.to_up)
			point.y -= game->ray.offset_v.y;
		else
			point.y += game->ray.offset_v.y;
		if (game->ray.to_left)
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
	while (!is_horizontal_wall(game->map, point, !game->ray.to_up))
	{
		// put_point(game, point.x, point.y, GREEN);
		if (game->ray.to_up)
			point.y -= game->ray.offset_h.y;
		else
			point.y += game->ray.offset_h.y;
		if (game->ray.to_left)
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
		game->ray.wall = 0;
		return (result_h);
	}
	else
	{
		game->ray.wall = 1;
		return (result_v);
	}
}

static	t_fpos	init_start_v(t_game *game)
{
	t_fpos	start;

	if (game->ray.to_left)
	{
		start.x = game->player.px.x - (game->player.map.x * TILE);
		start.y = game->player.px.y + start.x * tan(game->ray.angle);
		start.x = game->player.px.x - start.x;		
	}
	else
	{
		start.x = game->player.map.x * TILE + TILE - game->player.px.x;
		start.y = game->player.px.y - start.x * tan(game->ray.angle);
		start.x = game->player.px.x + start.x;
	}
	return (start);
}

static	t_fpos	init_start_h(t_game *game)
{
	t_fpos	start;

	if (game->ray.to_up)
	{
		start.y = game->player.px.y - (game->player.map.y * TILE);
		start.x = game->player.px.x - start.y / -tan(game->ray.angle);
		start.y = game->player.px.y - start.y;
	}
	else
	{
		start.y = game->player.map.y * TILE + TILE - game->player.px.y;
		start.x = game->player.px.x + start.y / -tan(game->ray.angle) ;
		start.y = game->player.px.y + start.y;		
	}
	return (start);
}

void	put_environnement(t_game *game)
{
	t_fpos	start_h;
	t_fpos	start_v;
	int		i;
	
	game->ray.angle = to_rad(ANGLE_PLAYER);
	game->ray.angle = game->player.angle + to_rad(FOV / 2);
	if (game->ray.angle > (2 * M_PI))
			game->ray.angle -= (2 * M_PI);
	i = 0;
	while (i < WIDTH)
	{
		game->ray.to_up = (game->ray.angle >= PI_0 && game->ray.angle < M_PI);
		game->ray.to_left = (game->ray.angle >= PI_90 && game->ray.angle < PI_270);
		start_h = init_start_h(game);
		if (start_h.x < MAX_MINIMAP)
			game->ray.offset_h.x = fabs(TILE / tan(game->ray.angle));
		game->ray.offset_h.y = TILE;
		start_v = init_start_v(game);
		game->ray.offset_v.y = fabs(TILE * tan(game->ray.angle));
		game->ray.offset_v.x = TILE;
		game->ray.px = get_collision(game, start_h, start_v);
		if (i == 0)
			game->ray1 = game->ray.px;
		else if (i == WIDTH - 1)
			game->ray2 = game->ray.px;
		put_column(game, i);
		game->ray.angle -= (to_rad(FOV) / (WIDTH));
		if (game->ray.angle < 0)
			game->ray.angle += (2 * M_PI);
		i++;
	}
	put_image(&game->render, &game->environnement, 0, 0);
}