/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/21 17:43:59 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3D.h"

static	int	get_scrolling(t_game *game)
{
	static int	tmp;
	if (tmp >= SCROLLING_SKY)
		tmp = 0;
	tmp++;
	return (tmp % game->sky.width * 2);
}

void	put_sky(t_game *game)
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
				get_color(game, &game->sky, i / ratio, offset));
			j++;
		}
		i++;
	}
}

t_img	*get_image(t_game *game, int temp)
{
	if (game->ray.wall_h)
	{
		if (game->ray.angle >= 0 && game->ray.angle < PI_180)
			return (&game->north);
		else
			return (&game->south);
	}
	else
	{
		if (game->ray.angle >= PI_90 && game->ray.angle < PI_270)
			return (&game->west);
		else
			return (&game->east);
	}
}

int	get_scrolling_offset(t_game *game, int temp)
{
	int	offset;
	int	scrolling;

	scrolling = temp / TILE % TILE;
	if (game->ray.wall_h)
	{
		if (game->ray.angle >= 0 && game->ray.angle < PI_180)
			offset = (int)(game->ray.px.x + scrolling) % TILE;
		else
			offset = abs((int)(game->ray.px.x - scrolling) % TILE - TILE);
	}
	else
	{
		if (game->ray.angle >= PI_90 && game->ray.angle < PI_270)
			offset = abs((int)(game->ray.px.y - scrolling) % TILE - TILE);
		else
			offset = (int)(game->ray.px.y + scrolling) % TILE;
	}
	return (offset);
}

void	put_column(t_game *game, int n)
{
	static int temp;
	static int temp2;
	float		ray_dist;
	float		size_column;
	int			middle;
	int			i;
	int			offset;
	int			color;
	float		ratio;

	if (temp > ANIMATION)
		temp = 0;
	if (temp2 > SCROLLING)
		temp2 = 0;

	ray_dist = hypotenus(game->player.px, game->ray.px) * cos(game->player.angle - game->ray.angle);
	ray_dist = fabs(TILE / ray_dist * HEIGHT);
	size_column = ray_dist / 2;
	middle = HEIGHT / 2;


	offset = get_scrolling_offset(game, temp2);

	ratio = TILE / ray_dist;
	t_img	*to_print = get_image(game, temp);

	i = 0;
	while(i < HEIGHT)
	{
		if (i < size_column)
		{
			color = *(int *)(to_print->addr + (int)((size_column - i) * ratio) * to_print->line + offset * 4);
			put_pixel(&game->environnement, n, middle - i, color);
			color = *(int *)(to_print->addr + (int)(i * ratio + TILE / 2) * to_print->line + offset * 4);
			put_pixel(&game->environnement, n, middle + i, color);
		}
		else
		{
			// color = *(int *)(game->sky.addr + (int)(HEIGHT % i) * game->sky.line + offset * 4);
			// put_pixel(&game->environnement, n, middle - i, color);
			put_pixel(&game->environnement, n, middle + i, FLOOR);
		}
		i++;
	}
	temp++;
	if (temp % 15 == 0)
		temp2++;
}