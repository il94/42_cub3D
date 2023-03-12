/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sky.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:57:42 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/11 23:25:17 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static	int	get_scrolling(t_game *game)
{
	static int	tmp;

	if (tmp >= SCROLLING)
		tmp = 0;
	tmp++;
	return (tmp % game->sky.width * 2);
}

void	put_sky_color(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(&game->environnement, j, i, game->c_color);
			j++;
		}
		i++;
	}
}

void	put_sky_image(t_game *game)
{
	int		scrolling;
	float	ratio;
	int		offset;
	int		i;
	int		j;

	ratio = (float)WIDTH / game->sky.width;
	scrolling = get_scrolling(game);
	i = 0;
	while (i < game->sky.height * ratio - HEIGHT / 2)
	{
		j = 0;
		while (j < game->sky.width * ratio)
		{
			offset = abs((int)(j / ratio + scrolling) % (int)(WIDTH / ratio));
			put_pixel(&game->environnement, j, i - 60,
				get_color(&game->sky, i / ratio, offset));
			j++;
		}
		i++;
	}
}
