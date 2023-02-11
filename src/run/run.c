/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/11 21:14:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
}

int	run(t_game *game)
{
	// usleep(7000);
	put_render(game);
	// move_player(game);
}
