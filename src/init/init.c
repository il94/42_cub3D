/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:19 by adouay            #+#    #+#             */
/*   Updated: 2023/02/20 14:25:05 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_player(t_game *game)
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

static void	init_images(t_game *game)
{
	game->render.img = NULL;
	game->environnement.img = NULL;
	game->full_minimap.img = NULL;
	game->minimap.img = NULL;

	game->north.img = NULL;
	game->south.img = NULL;
	game->west.img = NULL;
	game->east.img = NULL;
	game->sky.img = NULL;
	game->star.img = NULL;

	game->north_sprite_number = 0;
	game->south_sprite_number = 0;
	game->west_sprite_number = 0;
	game->east_sprite_number = 0;
}

static void	init_ray(t_game *game)
{
	game->ray.px.x = 0;
	game->ray.px.y = 0;
	game->ray.offset_h.x = 0;
	game->ray.offset_h.y = 0;
	game->ray.offset_v.x = 0;
	game->ray.offset_v.y = 0;
	game->ray.angle = 0;
	game->ray.door = 0;
}

static void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;

	game->map = NULL;
	game->size_map.x = 0;
	game->size_map.y = 0;
	game->sprite = NULL;
	game->fd = -1;
	game->file_content = NULL;

	game->mouse.x = WIDTH / 2;
	game->mouse.y = HEIGHT / 2;

	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
	game->move_dir_left = FALSE;
	game->move_dir_right = FALSE;
	game->mouse_on = FALSE;
}

void	init(t_game *game)
{
	init_game(game);
	init_ray(game);
	init_player(game);
	init_images(game);
}
