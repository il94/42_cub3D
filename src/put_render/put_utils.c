/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/11 23:31:01 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_mimg	*get_image(t_game *game)
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

int	get_color(t_mimg *src, int x, int y)
{
	return (*(int *)(src->addr + x * src->line + y * 4));
}

void	put_pixel(t_mimg *dst_myimg, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > dst_myimg->width || y > dst_myimg->height)
		return ;
	dst = dst_myimg->addr + y * dst_myimg->line + x * dst_myimg->bpp / 8;
	if (color >= -1 && y >= 0 && x >= 0 && color != *(int *)dst)
		*(unsigned int *)dst = color;
}

void	put_line(t_game *game, t_fpos start, t_fpos end, double coeff)
{
	t_pos	pos;
	double	error;

	pos.x = start.x;
	pos.y = start.y;
	error = 0;
	while (pos.x <= end.x)
	{
		put_pixel(&game->minimap, pos.x, pos.y, RED);
		error -= coeff;
		while (error < -0.5)
		{
			if (pos.x < end.x)
				put_pixel(&game->minimap, pos.x, pos.y, RED);
			if (start.y > end.y)
				pos.y--;
			else
				pos.y++;
			error += 1.0;
		}
		pos.x++;
	}
}

void	put_image(t_mimg *dst_myimg, t_mimg *src_img, int x, int y)
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
			put_pixel(dst_myimg, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
