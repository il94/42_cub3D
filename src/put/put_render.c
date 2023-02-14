/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/14 20:20:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	put_render(t_game *game)
{
	ray_casting(game);
	put_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->render.img, 0, 0);
}
