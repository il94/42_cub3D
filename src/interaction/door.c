/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:15:56 by adouay            #+#    #+#             */
/*   Updated: 2023/03/11 23:17:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	close_door(t_game *game, t_pos old_pos_map)
{
	if (old_pos_map.x != game->player.map.x
		|| old_pos_map.y != game->player.map.y)
	{
		if (game->map[old_pos_map.y][old_pos_map.x] == '3')
		{
			system("cvlc sounds/close_bar.wav &");
			game->map[old_pos_map.y][old_pos_map.x] = '2';
		}
	}
}

void	near_door(t_game *game)
{
	t_pos	map_ray3;
	float	distance;

	map_ray3.y = game->ray_mid.px.y;
	map_ray3.x = game->ray_mid.px.x;
	if (game->ray_mid.up && game->ray_mid.wall_h)
		map_ray3.y -= TILE;
	if (game->ray_mid.left && game->ray_mid.wall_v)
		map_ray3.x -= TILE;
	distance = hypotenus(game->player.px, game->ray_mid.px);
	map_ray3.x /= TILE;
	map_ray3.y /= TILE;
	if (distance < 2 * TILE && game->map[map_ray3.y][map_ray3.x] == '2'
		&& game->is_door == FALSE)
	{
		system("cvlc sounds/navi.wav &");
		game->is_door = TRUE;
	}
	else if (!(distance < 2 * TILE && game->map[map_ray3.y][map_ray3.x] == '2')
		&& game->is_door == TRUE)
		game->is_door = FALSE;
}

void	open_door(t_game *game)
{
	t_pos	map_ray3;
	float	distance;

	map_ray3.y = game->ray_mid.px.y;
	map_ray3.x = game->ray_mid.px.x;
	if (game->ray_mid.up && game->ray_mid.wall_h)
		map_ray3.y -= TILE;
	if (game->ray_mid.left && game->ray_mid.wall_v)
		map_ray3.x -= TILE;
	distance = hypotenus(game->player.px, game->ray_mid.px);
	map_ray3.x /= TILE;
	map_ray3.y /= TILE;
	if (distance < 2 * TILE && game->map[map_ray3.y][map_ray3.x] == '2')
	{
		game->star_state = 0;
		game->stars_apparead = TRUE;
		system("cvlc sounds/open_bar.wav &");
		game->map[map_ray3.y][map_ray3.x] = '3';
	}
}
