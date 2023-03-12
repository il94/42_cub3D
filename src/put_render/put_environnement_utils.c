/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_environnement_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:39:28 by adouay            #+#    #+#             */
/*   Updated: 2023/03/11 22:43:42 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_offset(t_game *game)
{
	game->ray.offset_h.y = TILE;
	game->ray.offset_v.x = TILE;
	game->ray.offset_h.x = fabs(TILE / tan(game->ray.angle));
	game->ray.offset_v.y = fabs(TILE * tan(game->ray.angle));
}

t_bool	is_vertical_wall(char **map, t_fpos src, t_bool to_right)
{
	t_pos	pos;

	pos.x = src.x / TILE - 1 + to_right;
	pos.y = src.y / TILE;
	if (pos.y < 0 || pos.y >= ft_get_size_array(map))
		return (1);
	return (pos.x < 0 || pos.x > ft_strlen(map[pos.y])
		|| map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == '2');
}

t_bool	is_horizontal_wall(char **map, t_fpos src, t_bool to_down)
{
	t_pos	pos;

	pos.x = src.x / TILE;
	pos.y = src.y / TILE - 1 + to_down;
	if (pos.y < 0 || pos.y >= ft_get_size_array(map))
		return (1);
	if (pos.x < 0 || pos.x >= ft_strlen(map[pos.y]))
		return (1);
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == '2')
		return (1);
	return (0);
}

t_fpos	init_start_v(t_game *game)
{
	t_fpos	start;

	if (game->ray.left)
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

t_fpos	init_start_h(t_game *game)
{
	t_fpos	start;

	if (game->ray.up)
	{
		start.y = game->player.px.y - (game->player.map.y * TILE);
		start.x = game->player.px.x - start.y / -tan(game->ray.angle);
		start.y = game->player.px.y - start.y;
	}
	else
	{
		start.y = game->player.map.y * TILE + TILE - game->player.px.y;
		start.x = game->player.px.x + start.y / -tan(game->ray.angle);
		start.y = game->player.px.y + start.y;
	}
	return (start);
}
