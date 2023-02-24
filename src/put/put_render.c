/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/24 21:38:18 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	put_render(t_game *game)
{
	if (game->image_sky)
		put_sky_image(game);
	else
		put_sky_color(game);
	put_environnement(game);
	// if (game->stars_apparead)
		put_stars(game);
	put_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->render.img, 0, 0);
}
