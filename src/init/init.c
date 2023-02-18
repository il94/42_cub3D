/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:19 by adouay            #+#    #+#             */
/*   Updated: 2023/02/18 17:42:27 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_player_struct(t_game *game)
{
	game->player.map.x = 0;
	game->player.map.y = 0;
	game->player.px.x = 0;
	game->player.px.y = 0;
	game->player.angle = 0;
	game->player.dir.x = cos(game->player.angle) * SPEED;
	game->player.dir.y = -sin(game->player.angle) * SPEED;
	game->player.dir_side.x = cos(game->player.angle + to_rad(90)) * SPEED;
	game->player.dir_side.y = -sin(game->player.angle + to_rad(90)) * SPEED;
}

static void	init_game_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	game->size_map.x = 0;
	game->size_map.y = 0;
	game->sprite = NULL;
	game->fd = -1;
	game->file_content = NULL;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
	game->move_dir_left = FALSE;
	game->move_dir_right = FALSE;

	game->ray.px.x = 0;
	game->ray.px.y = 0;
	game->ray.offset_h.x = 0;
	game->ray.offset_h.y = 0;
	game->ray.offset_v.x = 0;
	game->ray.offset_v.y = 0;
	game->ray.angle = 0;

	game->mouse.x = 0;
	game->mouse.y = 0;
	
	game->render.img = NULL;
	game->environnement.img = NULL;
	game->minimap.img = NULL;
	game->trimmed_minimap.img = NULL;
	
	game->north.img = NULL;
	game->south.img = NULL;
	game->west.img = NULL;
	game->east.img = NULL;

	// game->north_a = NULL
	// game->north_sprite_number = 0;

}

void	init(t_game *game)
{
	init_game_struct(game);
	init_player_struct(game);
}
