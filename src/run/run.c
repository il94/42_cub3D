/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:50:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/16 01:05:23 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	run(t_game *game)
{
	usleep(30000);
	put_render(game);
	process_inputs(game);
	// printf("POS : x = %f | y = %f\nDIR : x = %f | y = %f\n============\n", game->player.px.x, game->player.px.y, game->player.dir_side.x, game->player.dir_side.y);
	// printf("POS : x = %d | y = %d\n============\n", game->player.map.x, game->player.map.y);
}
