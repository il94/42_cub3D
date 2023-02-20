/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/20 04:10:36 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3D.h"

void	put_sky(t_game *game)
{
	t_fpos	temp;
	static int	tmp;
	if (tmp >= SCROLLING_SKY)
		tmp = 0;
	int	scrolling = tmp % game->sky.width * 2;
	float	ray_dist;
	int		middle;
	int		i;
	int		j;
	middle = HEIGHT / 2;
	i = 0;

	int	color;
	float	ratio_x;
	float	ratio_y;

	ratio_x = (float)WIDTH / game->sky.width;
	int	offset;
	while (i < game->sky.height * ratio_x - HEIGHT / 2)
	{
		j = 0;
		while (j < game->sky.width * ratio_x)
		{
			offset = abs(((int)(j / ratio_x + scrolling) % (int)(WIDTH / ratio_x)));
			color = *(int *)(game->sky.addr + (int)(i / ratio_x) * game->sky.line + offset * 4);
			put_pixel(&game->environnement, j, i - 60, color);
			j++;
		}
		i++;
	}
	tmp++;
}

t_img	*get_image_ANIMATION(t_game *game, int temp)
{
	return (&game->north);

	// if (game->ray.wall_h)
	// {
	// 	if (game->ray.angle >= 0 && game->ray.angle < PI_180)
	// 	{
	// 		if (temp < ANIMATION / 4)
	// 			return (&game->north_a[0]);
	// 		else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
	// 			return (&game->north_a[1]);
	// 		else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
	// 			return (&game->north_a[2]);
	// 		else
	// 			return (&game->north_a[3]);
	// 		// return (&game->west);
	// 	}
	// 	else
	// 	{
	// 		if (temp < ANIMATION / 4)
	// 			return (&game->north_a[0]);
	// 		else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
	// 			return (&game->north_a[1]);
	// 		else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
	// 			return (&game->north_a[2]);
	// 		else
	// 			return (&game->north_a[3]);
	// 		// return (&game->east);
	// 	}
	// }
	// else
	// {
	// 	if (game->ray.angle >= PI_90 && game->ray.angle < PI_270)
	// 	{
	// 		if (temp < ANIMATION / 4)
	// 			return (&game->north_a[0]);
	// 		else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
	// 			return (&game->north_a[1]);
	// 		else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
	// 			return (&game->north_a[2]);
	// 		else
	// 			return (&game->north_a[3]);
	// 	}
	// 	else
	// 	{
	// 		if (temp < ANIMATION / 4)
	// 			return (&game->north_a[0]);
	// 		else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
	// 			return (&game->north_a[1]);
	// 		else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
	// 			return (&game->north_a[2]);
	// 		else
	// 			return (&game->north_a[3]);
	// 		// return (&game->south);
	// 	}
	// }
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
	t_img	*to_print = get_image_ANIMATION(game, temp);

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