/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/10 19:04:37 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	move_player(t_game *game)
{
	if (game->move_up)
		game->player.px_y -= 5;
	if (game->move_right)
		game->player.px_x += 5;
	if (game->move_down)
		game->player.px_y += 5;
	if (game->move_left)
		game->player.px_x -= 5;

	if (game->move_dir_left)
	{
		game->player.angle += 0.1;
		if (game->player.angle > (2 * M_PI))
			game->player.angle = 0;
		game->player.dir_x = cos(game->player.angle) * 10;
		game->player.dir_y = -sin(game->player.angle) * 10;
	}
	if (game->move_dir_right)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle = (2 * M_PI);
		game->player.dir_x = cos(game->player.angle) * 10;
		game->player.dir_y = -sin(game->player.angle) * 10;
	}	
}

int	run(t_game *game)
{
	usleep(7000);
	put_render(game);
	move_player(game);
}