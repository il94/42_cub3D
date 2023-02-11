/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:19 by adouay            #+#    #+#             */
/*   Updated: 2023/02/11 21:27:19 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_player_struct(t_game *game)
{
	game->player.angle = to_rad(FOV);
	game->player.dir_x = cos(game->player.angle) * TILE;
	game->player.dir_y = -sin(game->player.angle) * TILE;
}

static void	init_game_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	game->sprite = NULL;
	game->fd = -1;
	game->file_content = NULL;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
}

void	init(t_game *game)
{
	init_game_struct(game);
	init_player_struct(game);
}