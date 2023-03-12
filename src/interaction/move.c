/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:27:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/11 22:56:11 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	move_mouse(int x, t_game *game)
{	
	if (game->mouse_on)
	{
		if (x < game->mouse.x)
			game->player.angle = correc_angle(game->player.angle + SENSI_MOUSE);
		else if (x > game->mouse.x)
			game->player.angle = correc_angle(game->player.angle - SENSI_MOUSE);
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}

void	move_player(t_game *game, float x, float y)
{
	t_pos	target;
	t_pos	old_pos_map;

	old_pos_map = game->player.map;
	target.x = x / TILE;
	target.y = y / TILE;
	if (game->map[game->player.map.y][target.x] == '0'
		|| game->map[game->player.map.y][target.x] == '3'
		|| check_player_carac(game->map[game->player.map.y][target.x]))
		game->player.px.x = x;
	if (game->map[target.y][game->player.map.x] == '0'
		|| game->map[target.y][game->player.map.x] == '3'
		|| check_player_carac(game->map[target.y][game->player.map.x]))
		game->player.px.y = y;
	if (game->map[(int)game->player.px.y / TILE]
		[(int)game->player.px.x / TILE] != '1')
	{
		game->player.map.x = game->player.px.x / TILE;
		game->player.map.y = game->player.px.y / TILE;
	}
	close_door(game, old_pos_map);
}
