/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:15:56 by adouay            #+#    #+#             */
/*   Updated: 2023/02/21 17:25:07 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	door_animation(t_game *game)
{
	
}

void	open_door(t_game *game)
{
	t_pos	map_ray3;
	float	distance;

	map_ray3.y = game->ray3.px.y;	
	map_ray3.x = game->ray3.px.x;
	if (game->ray3.up && game->ray3.wall_h)
		map_ray3.y -= TILE;
	if (game->ray3.left && game->ray3.wall_v)
		map_ray3.x -= TILE;
	distance = hypotenus(game->player.px,game->ray3.px);
	map_ray3.x /= TILE;
	map_ray3.y /= TILE;
	if (distance < 2 * TILE && game->map[map_ray3.y][map_ray3.x] == '2')
	{
		door_animation(game);
		system("cvlc sounds/open_bar.wav &");
		game->map[map_ray3.y][map_ray3.x] = '3';
	}
}