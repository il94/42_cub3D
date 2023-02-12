/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/12 22:23:48 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	move_player_map(t_game *game, int x, int y)
{
	char	c;

	c = game->map[game->player.map_y][game->player.map_x];

	if (c != '1' && game->map[y][x] != '1')
	{
		game->map[game->player.map_y][game->player.map_x] = '0';
		game->map[y][x] = 'N';
	}
}

void	move_player(t_game *game)
{
	if (game->move_up)
	{
		game->player.px_y -= 5;
		if (game->player.px_y <= 0)
			game->player.px_y = 0;
		if ((int)game->player.px_y / TILE == 0)
			game->player.map_y -= 1;
	}
	if (game->move_right)
	{
		game->player.px_x += 5;
		if (game->player.px_x >= W_MINIMAP)
			game->player.px_x = W_MINIMAP;
		if ((int)game->player.px_x / TILE == 0)
			game->player.map_x += 1;
	}
	if (game->move_down)
	{
		game->player.px_y += 5;
		if (game->player.px_y >= H_MINIMAP)
			game->player.px_y = H_MINIMAP;
		if ((int)game->player.px_y / TILE == 0)
			game->player.map_y -= 1;
	}
	if (game->move_left)
	{
		game->player.px_x -= 5;
		if (game->player.px_x <= 0)
			game->player.px_x = 0;
		if ((int)game->player.px_y / TILE == 0)
			game->player.map_x -= 1;
	}
	if (game->player.px_x < game->player.map_x * TILE)
	{
		move_player_map(game, game->player.map_x - 1, game->player.map_y);
		game->player.map_x -= 1;
	}
	else if (game->player.px_x > (game->player.map_x + 1) * TILE)
	{
		move_player_map(game, game->player.map_x + 1, game->player.map_y);
		game->player.map_x += 1;
	}
	if (game->player.px_y < game->player.map_y * TILE)
	{
		move_player_map(game, game->player.map_x, game->player.map_y + 1);
		game->player.map_y -= 1;
	}
	else if (game->player.px_y > (game->player.map_y + 1) * TILE)
	{
		move_player_map(game, game->player.map_x, game->player.map_y - 1);
		game->player.map_y += 1;
	}


	if (game->move_dir_left)
	{
		game->player.angle += 0.1;
		if (game->player.angle > (2 * M_PI))
			game->player.angle = 0.00001;
	}
	if (game->move_dir_right)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0.00005)
			game->player.angle = (2 * M_PI - 0.00001);
	}
	game->player.dir_x = cos(game->player.angle) * TILE * 2;
	game->player.dir_y = -sin(game->player.angle) * TILE * 2;
}

int	run(t_game *game)
{
	usleep(45000);
	put_render(game);
	move_player(game);
}
