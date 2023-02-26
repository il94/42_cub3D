/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/27 00:19:13 by ilandols         ###   ########.fr       */
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

int	get_color(t_game *game, t_img *src, int x, int y)
{
	return (*(int *)(src->addr + x * src->line + y * 4));
}

void	put_pixel(t_img *dst_img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > dst_img->width || y > dst_img->height)
		return ;
	dst = dst_img->addr + y * dst_img->line + x * dst_img->bpp / 8;
	if (color >= -1 && y >= 0 && x >= 0 && color != *(int *)dst)
		*(unsigned int *)dst = color;
}

void	put_image(t_img *dst_img, t_img *src_img, int x, int y)
{
	int		color;
	int		i;
	int		j;

	i = 0;
	while (i < src_img->width)
	{
		j = 0;
		while (j < src_img->height)
		{
			color = *(int *)(src_img->addr + j * src_img->line + i * 4);
			put_pixel(dst_img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
