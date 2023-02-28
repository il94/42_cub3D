/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:36:12 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/28 14:48:34 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_mlx_addr(t_game *game)
{
	game->render.addr = new_get_data_addr(game, &game->render);
	game->full_minimap.addr = new_get_data_addr(game, &game->full_minimap);
	game->environnement.addr = new_get_data_addr(game, &game->environnement);
	game->minimap.addr = new_get_data_addr(game, &game->minimap);
	game->north.addr = new_get_data_addr(game, &game->north);
	game->south.addr = new_get_data_addr(game, &game->south);
	game->west.addr = new_get_data_addr(game, &game->west);
	game->east.addr = new_get_data_addr(game, &game->east);
	if (game->image_sky)
		game->sky.addr = new_get_data_addr(game, &game->sky);
	game->star.addr = new_get_data_addr(game, &game->star);
	game->player_minimap.addr = new_get_data_addr(game, &game->player_minimap);
}

static void	init_mlx_img(t_game *game)
{
	game->render.img = new_mlx_new_image(game, &game->render, WIDTH, HEIGHT);
	game->environnement.img = new_mlx_new_image(game, &game->environnement,
			WIDTH, HEIGHT);
	game->full_minimap.img = new_mlx_new_image(game, &game->full_minimap,
			MNMP_WIDTH, MNMP_HEIGHT);
	game->minimap.img = new_mlx_new_image(game, &game->minimap,
			MINIMAP, MINIMAP);
	game->north.img = new_xpm_to_image(game, &game->north, game->sprite[NO]);
	game->south.img = new_xpm_to_image(game, &game->south, game->sprite[SO]);
	game->east.img = new_xpm_to_image(game, &game->east, game->sprite[EA]);
	game->west.img = new_xpm_to_image(game, &game->west, game->sprite[WE]);
	if (game->image_sky)
		game->sky.img = new_xpm_to_image(game, &game->sky, game->sprite[C]);
	game->star.img = new_xpm_to_image(game, &game->star,
			"sprites/xpm/yellow_star.xpm");
	game->player_minimap.img = new_xpm_to_image(game, &game->player_minimap,
			"sprites/xpm/m_40.xpm");
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	verify_alloc(game, game->mlx_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	verify_alloc(game, game->win_ptr);
	init_mlx_img(game);
	init_mlx_addr(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, key_release, game);
	mlx_hook(game->win_ptr, 6, 1L << 6, move_mouse, game);
	draw_minimap(game);
	mlx_hook(game->win_ptr, 17, 0, mlx_loop_end, game->mlx_ptr);
	system("cvlc sounds/star_way.wav &");
	mlx_loop_hook(game->mlx_ptr, run, game);
	mlx_loop(game->mlx_ptr);
}
