/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:15:56 by adouay            #+#    #+#             */
/*   Updated: 2023/02/18 18:36:11 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	looking_door(t_game *game, int y, int x)
{
	t_pos	map_ray1;
	t_pos	map_ray2;

	map_ray1.x = game->ray1.px.x / TILE;
	map_ray1.x = game->ray1.px.y / TILE;
	map_ray2.x = game->ray2.px.x / TILE;
	map_ray2.x = game->ray2.px.y / TILE;
	if (game->ray1.wall_h != game->ray2.wall_h)
		return (0);
	if (map_ray1.x != map_ray2.x || map_ray1.y != map_ray2.y)
		return (0);
	return (1);
}

static void	close_open_door(t_game *game, int y, int x)
{
	if (looking_door(game, y, x))
		if (game->map[y][x] == '2')
			game->map[y][x] = '3';
	return ;
}

void	check_for_door(t_game *game)
{
	int	y;
	int	x;

	y = game->player.map.y;
	x = game->player.map.x;
	close_open_door(game, y - 1, x);
	close_open_door(game, y + 1, x);
	close_open_door(game, y, x - 1);
	close_open_door(game, y, x + 1);
}
