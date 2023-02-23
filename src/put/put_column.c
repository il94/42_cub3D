/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/23 23:47:38 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_img	*get_image(t_game *game)
{
	if (game->ray.wall_h)
	{
		if (game->ray.up)
			return (&game->north);
		else
			return (&game->south);
	}
	else
	{
		if (game->ray.left)
			return (&game->west);
		else
			return (&game->east);
	}
}

static int	set_scrolling(int src, int max)
{
	if (src > SCROLLING)
		return (0);
	else
		return (src + 1);
}

int	get_scrolling_offset(t_game *game)
{
	int			scrolling;
	static int	temp;
	static int	temp2;

	temp = set_scrolling(temp, SCROLLING);
	if (temp % 15 == 0)
		temp2 = set_scrolling(temp2, SCROLLING);
	scrolling = temp2 / TILE % TILE;
	if (game->ray.wall_h)
	{
		if (game->ray.up)
			return ((int)(game->ray.px.x + scrolling) % TILE);
		else
			return (abs((int)(game->ray.px.x - scrolling) % TILE - TILE));
	}
	else
	{
		if (game->ray.left)
			return (abs((int)(game->ray.px.y - scrolling) % TILE - TILE));
		else
			return ((int)(game->ray.px.y + scrolling) % TILE);
	}
}

void	put_column(t_game *game, t_img *to_print, float ray_dist, int n)
{
	int			i;
	int			offset;
	float		ratio;

	offset = get_scrolling_offset(game);
	ratio = TILE / ray_dist;
	i = 0;
	while (i < HEIGHT)
	{
		if (i < ray_dist / 2)
		{
			put_pixel(&game->environnement, n, HEIGHT / 2 - i,
				get_color(game, to_print, (ray_dist / 2 - i) * ratio, offset));
			put_pixel(&game->environnement, n, HEIGHT / 2 + i,
				get_color(game, to_print, i * ratio + TILE / 2, offset));
		}
		else
			put_pixel(&game->environnement, n, HEIGHT / 2 + i, FLOOR);
		i++;
	}
}
