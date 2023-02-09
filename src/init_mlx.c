/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:36:12 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/09 16:57:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	verify_alloc(game, game->mlx_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1500, 1300, "Cub3D");
	verify_alloc(game, game->win_ptr);

	game->minimap.img = mlx_new_image(game->mlx_ptr, 1500, 1300);
	verify_alloc(game, game->minimap.img);
	game->minimap.addr = mlx_get_data_addr(game->minimap.img, &game->minimap.bpp, &game->minimap.line, &game->minimap.end);
	verify_alloc(game, game->minimap.addr);


	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	// mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win_ptr, 17, 0, mlx_loop_end, game->mlx_ptr);
	mlx_loop_hook(game->mlx_ptr, run, game);
	mlx_loop(game->mlx_ptr);
}