/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:26:26 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/11 23:31:01 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	*new_get_data_addr(t_game *game, t_mimg *sprite)
{
	void	*addr;

	addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line, &sprite->end);
	verify_alloc(game, addr);
	return (addr);
}

void	*new_mlx_new_image(t_game *game, t_mimg *sprite, int width, int height)
{
	void	*image;

	image = mlx_new_image(game->mlx_ptr, width, height);
	verify_alloc(game, image);
	sprite->width = width;
	sprite->height = height;
	return (image);
}

void	*new_xpm_to_image(t_game *game, t_mimg *sprite, char *path)
{
	void	*image;

	image = mlx_xpm_file_to_image(game->mlx_ptr, path, &sprite->width,
			&sprite->height);
	verify_alloc(game, image);
	return (image);
}
