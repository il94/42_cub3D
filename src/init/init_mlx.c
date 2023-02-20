/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:36:12 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/20 14:31:01 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_mlx_addr(t_game *game)
{
	game->render.addr = mlx_get_data_addr(game->render.img,
			&game->render.bpp, &game->render.line, &game->render.end);
	verify_alloc(game, game->render.addr);
	game->full_minimap.addr = mlx_get_data_addr(game->full_minimap.img,
			&game->full_minimap.bpp, &game->full_minimap.line, &game->full_minimap.end);
	verify_alloc(game, game->full_minimap.addr);
	game->environnement.addr = mlx_get_data_addr(game->environnement.img,
			&game->environnement.bpp, &game->environnement.line, &game->environnement.end);
	verify_alloc(game, game->environnement.addr);
	game->minimap.addr = mlx_get_data_addr(game->minimap.img,
			&game->minimap.bpp, &game->minimap.line, &game->minimap.end);
	verify_alloc(game, game->minimap.addr);
	game->north.addr = mlx_get_data_addr(game->north.img,
			&game->north.bpp, &game->north.line, &game->north.end);
	verify_alloc(game, game->north.addr);
	game->south.addr = mlx_get_data_addr(game->south.img,
			&game->south.bpp, &game->south.line, &game->south.end);
	verify_alloc(game, game->south.addr);
	game->west.addr = mlx_get_data_addr(game->west.img,
			&game->west.bpp, &game->west.line, &game->west.end);
	verify_alloc(game, game->west.addr);
	game->east.addr = mlx_get_data_addr(game->east.img,
			&game->east.bpp, &game->east.line, &game->east.end);
	verify_alloc(game, game->east.addr);


	game->sky.addr = mlx_get_data_addr(game->sky.img,
			&game->sky.bpp, &game->sky.line, &game->sky.end);
	verify_alloc(game, game->sky.addr);

}

static void	*new_mlx_new_image(t_game *game, t_img *img_struct, int width, int height)
{
	void	*image;

	image = mlx_new_image(game->mlx_ptr, width, height);
	verify_alloc(game, image);
	img_struct->width = width;
	img_struct->height = height;
	return (image);
}

static void	init_mlx_img(t_game *game)
{
	game->render.img = new_mlx_new_image(game, &game->render, WIDTH, HEIGHT);
	
	game->full_minimap.img = mlx_new_image(game->mlx_ptr, TILE_MINIMAP * (game->size_map.x / TILE) + 1, TILE_MINIMAP * (game->size_map.y / TILE) + 1);
	verify_alloc(game, game->full_minimap.img);
	game->full_minimap.width = TILE_MINIMAP * (game->size_map.x / TILE) + 1;
	game->full_minimap.height = TILE_MINIMAP * (game->size_map.y / TILE) + 1;
	game->environnement.img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	verify_alloc(game, game->environnement.img);
	game->environnement.width = WIDTH;
	game->environnement.height = HEIGHT;
	game->minimap.img = mlx_new_image(game->mlx_ptr, TMP_MAP, TMP_MAP);
	verify_alloc(game, game->minimap.img);
	game->minimap.width = TMP_MAP;
	game->minimap.height = TMP_MAP;
	game->north.img = mlx_xpm_file_to_image(game->mlx_ptr, game->sprite[NO],
		&game->north.width, &game->north.height);
	verify_alloc(game, game->north.img);
	game->south.img = mlx_xpm_file_to_image(game->mlx_ptr, game->sprite[SO],
		&game->south.width, &game->south.height);
	verify_alloc(game, game->south.img);
	game->west.img = mlx_xpm_file_to_image(game->mlx_ptr, game->sprite[WE],
		&game->west.width, &game->west.height);
	verify_alloc(game, game->west.img);
	game->east.img = mlx_xpm_file_to_image(game->mlx_ptr, game->sprite[EA],
		&game->east.width, &game->east.height);
	verify_alloc(game, game->east.img);


	game->sky.img = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/xpm/stars.xpm",
		&game->sky.width, &game->sky.height);
	verify_alloc(game, game->sky.img);

}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	verify_alloc(game, game->mlx_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	verify_alloc(game, game->win_ptr);
	init_mlx_img(game);
	init_mlx_addr(game);
	mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, key_release, game);
	mlx_hook(game->win_ptr, 6, 1L << 6, mouse_move, game);
	draw_minimap(game);
	mlx_hook(game->win_ptr, 17, 0, mlx_loop_end, game->mlx_ptr);
	mlx_loop_hook(game->mlx_ptr, run, game);
	mlx_loop(game->mlx_ptr);
}
