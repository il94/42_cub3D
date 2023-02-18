/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/18 19:02:28 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

/* SIGSEV map ouverte */

	// usleep(60000);
int	run(t_game *game)
{
	put_render(game);
	process_inputs(game);
}
	// printf("ANGLE PLAYER = %f\nDIR : x = %f | y = %f\nDIR SIDE : x = %f | y = %f\n\n============\n", game->player.angle, game->player.dir.x, game->player.dir.y, game->player.dir_side.x, game->player.dir_side.y);
	// printf("POS : x = %f | y = %f\nDIR : x = %f | y = %f\n============\n", game->player.px.x, game->player.px.y, game->player.dir_side.x, game->player.dir_side.y);
	// printf("POS : x = %d | y = %d\n============\n", game->player.map.x, game->player.map.y);