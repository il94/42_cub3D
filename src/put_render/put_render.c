/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/28 15:56:53 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	put_tilted_image(t_myimg *dst_myimg, t_myimg *src_img, t_pos pos, int angle)
{
	int		color;
	int		i;
	int		j;

	t_pos	tilt;

	tilt.x = src_img->width - cos(angle) * 5;
	tilt.y = src_img->height - sin(angle) * 5;

	// tilt.x = 


	i = 0;
	while (i < src_img->width)
	{
		j = 0;
		while (j < src_img->height)
		{
			color = *(int *)(src_img->addr + (tilt.y - j) * src_img->line + (tilt.x - i) * 4);
			put_pixel(dst_myimg, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

static void	test(t_game *game)
{
	t_pos	pos;
	int		angle;

	pos.x = WIDTH / 2;
	pos.y = HEIGHT / 2;
	angle = 180;
	put_tilted_image(&game->render, &game->player_minimap, pos, angle);
	// put_image(&game->render, &game->player_minimap, WIDTH / 2, HEIGHT / 2);
}

void	put_render(t_game *game)
{
	if (game->image_sky)
		put_sky_image(game);
	else
		put_sky_color(game);
	put_environnement(game);
	if (game->stars_apparead)
		put_stars(game);
	put_minimap(game);
	test(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->render.img, 0, 0);
}
