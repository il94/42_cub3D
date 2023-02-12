/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/12 12:43:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	move_player(t_game *game)
{
	if (game->move_up)
	{
		game->player.px_y -= 5;
		if (game->player.px_y <= 0)
			game->player.px_y = 0;
	}
	if (game->move_right)
	{
		game->player.px_x += 5;
		if (game->player.px_x >= W_MINIMAP)
			game->player.px_x = W_MINIMAP;
	}
	if (game->move_down)
	{
		game->player.px_y += 5;
		if (game->player.px_y >= H_MINIMAP)
			game->player.px_y = H_MINIMAP;
	}
	if (game->move_left)
	{
		game->player.px_x -= 5;
		if (game->player.px_x <= 0)
			game->player.px_x = 0;
	}



	if (game->move_dir_left)
	{
		game->player.angle += 0.1;
		if (game->player.angle > (2 * M_PI))
			game->player.angle = 0;
		game->player.dir_x = cos(game->player.angle) * TILE;
		game->player.dir_y = -sin(game->player.angle) * TILE;
	}
	if (game->move_dir_right)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle = (2 * M_PI);
		game->player.dir_x = cos(game->player.angle) * TILE;
		game->player.dir_y = -sin(game->player.angle) * TILE;
	}
}

int	run(t_game *game)
{
	usleep(7000);
	put_render(game);
	move_player(game);
}
