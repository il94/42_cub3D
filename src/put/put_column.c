/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/19 16:45:45 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3D.h"

t_img	*get_image_ANIMATION(t_game *game, int temp)
{
	if (game->ray.wall_h)
	{
		if (game->ray.angle >= 0 && game->ray.angle < PI_180)
		{
			if (temp < ANIMATION / 4)
				return (&game->north_a[0]);
			else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
				return (&game->north_a[1]);
			else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
				return (&game->north_a[2]);
			else
				return (&game->north_a[3]);
			// return (&game->west);
		}
		else
		{
			if (temp < ANIMATION / 4)
				return (&game->north_a[0]);
			else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
				return (&game->north_a[1]);
			else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
				return (&game->north_a[2]);
			else
				return (&game->north_a[3]);
			// return (&game->east);
		}
	}
	else
	{
		if (game->ray.angle >= PI_90 && game->ray.angle < PI_270)
		{
			if (temp < ANIMATION / 4)
				return (&game->north_a[0]);
			else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
				return (&game->north_a[1]);
			else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
				return (&game->north_a[2]);
			else
				return (&game->north_a[3]);
		}
		else
		{
			if (temp < ANIMATION / 4)
				return (&game->north_a[0]);
			else if (temp >= ANIMATION / 4 && temp < ANIMATION / 4 * 2)
				return (&game->north_a[1]);
			else if (temp >= ANIMATION / 4 * 2 && temp < ANIMATION / 4 * 3)
				return (&game->north_a[2]);
			else
				return (&game->north_a[3]);
			// return (&game->south);
		}
	}
}

int	get_offset_SCROLLING(t_game *game, int temp)
{
	int	offset;
	int	scrolling;

	scrolling = temp / TILE % TILE;
	// if (scrolling >= 127)
	// 	printf("scrolling = %d\n", scrolling);

	// if (temp < SCROLLING / 4)
	// 	scrolling = 1;
	// else if (temp >= SCROLLING / 4 && temp < SCROLLING / 4 * 2)
	// 	scrolling = 2;
	// else if (temp >= SCROLLING / 4 * 2 && temp < SCROLLING / 4 * 3)
	// 	scrolling = 3;
	// else
	// 	scrolling = 4;
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
	// if (offset > TILE)
	// {
		
	// 	printf("off = %d\n", offset);
	// }
	return (offset);
}


void	put_column(t_game *game, int n)
{
	static int temp;
	static int temp2;
	if (temp > ANIMATION)
		temp = 0;
	if (temp2 > SCROLLING)
		temp2 = 0;
		// printf("tmp = %d\n", temp2);
	// int temp2 = temp / 128;
	float	ray_dist;
	float	size_column;
	int		middle;
	int		i;
	int j = 0;
	ray_dist = hypotenus(game->player.px, game->ray.px) * cos(game->player.angle - game->ray.angle);
	ray_dist = fabs(TILE / ray_dist * HEIGHT);
	size_column = ray_dist / 2;
	middle = HEIGHT / 2;
	i = 0;

	int	offset;

	// if (game->ray.wall_h)
	offset = get_offset_SCROLLING(game, temp2);
		// offset = (int)game->ray.px.x % TILE;
	// else if (game->ray.wall_v)
		// offset = (int)game->ray.px.y % TILE;
	// if (offset > TILE)
	// 	offset = TILE;
	int	color;
	float	ratio;
	float		start;

	start = HEIGHT / 2 - size_column / 2;
	ratio = TILE / ray_dist;
	t_img	*to_print = get_image_ANIMATION(game, temp);
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
			put_pixel(&game->environnement, n, middle - i, SKY);
			put_pixel(&game->environnement, n, middle + i, FLOOR);
		}
		i++;

		/* only colors */
		
		// if (i < size_column && i >= size_column - 3)
		// {
		// 	put_pixel(&game->environnement, n, middle - i, BLACK);
		// 	put_pixel(&game->environnement, n, middle + i, BLACK);
		// }
		// else if (i < size_column)
		// {
		// 	if (game->ray.wall)
		// 	{
		// 		put_pixel(&game->environnement, n, middle - i, BROWN);
		// 		put_pixel(&game->environnement, n, middle + i, BROWN);
		// 	}
		// 	else
		// 	{
		// 		put_pixel(&game->environnement, n, middle - i, D_BROWN);
		// 		put_pixel(&game->environnement, n, middle + i, D_BROWN);
		// 	}
		// }
		// else
		// {
		// 	put_pixel(&game->environnement, n, middle - i, BLUE);
		// 	put_pixel(&game->environnement, n, middle + i, GREEN);
		// }
		// i++;

		/**/
	}
	temp++;
	if (temp % 15 == 0)
		temp2++;
}