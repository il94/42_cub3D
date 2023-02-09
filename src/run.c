/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/09 19:54:52 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	move_player(t_game *game)
{
	if (game->move_up)
	{
		game->player.y -= 5;
		game->player.dir_y -= 5;
		
	}
	if (game->move_right)
	{
		game->player.x += 5;
		game->player.dir_x += 5;
	}
	if (game->move_down)
	{
		game->player.y += 5;
		game->player.dir_y += 5;
	}
	if (game->move_left)
	{
		game->player.x -= 5;
		game->player.dir_x -= 5;		
	}
}

int	run(t_game *game)
{
	put_render(game);
	move_player(game);
}