/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/17 20:12:48 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3D.h"

// t_img	*get_image(t_game *game)
// {
// 	if (game->ray.wall_h)
// 	{
// 		// return (&game->)
// 	}
// 	else
// 	{
// 		if (game->ray.angle >= PI_90 && game->ray.angle < PI_270)	
// 		{
			
// 		}	
// 	}
// }

void	put_column(t_game *game, int n)
{
	static int temp;
	if (temp > ANIMATION)
		temp = 0;
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

	if (game->ray.wall_h)
		offset = (int)game->ray.px.x % TILE;
	else if (game->ray.wall_v)
		offset = (int)game->ray.px.y % TILE;

	int	color;
	float	ratio;
	float		start;

	start = HEIGHT / 2 - size_column / 2;
	ratio = TILE / ray_dist;
	// printf("offset = %d\n", offset);
	// printf("ratio = %f\n", ratio);
	// printf("size_column = %f\n", size_column);
	while(i < HEIGHT)
	{
		
		if (i < size_column)
		{
			if (game->ray.wall_h)
			{
				if (game->ray.angle >= 0 && game->ray.angle < PI_180)
				{
					color = *(int *)(game->west.addr + (int)((size_column - i) * ratio) * game->west.line + offset * 4);
					// if (ray_dist / 2 <= 10)
						// printf("ray_dist = %f\n", ray_dist / 2);
					put_pixel(&game->environnement, n, middle - (i), color);
					color = *(int *)(game->west.addr + (int)(i * ratio + TILE / 2) * game->west.line + offset * 4);
					put_pixel(&game->environnement, n, middle + i, color);
				}
				else
				{
					color = *(int *)(game->east.addr + (int)((size_column - i) * ratio) * game->east.line + offset * 4);
					// if (ray_dist / 2 <= 10)
						// printf("ray_dist = %f\n", ray_dist / 2);
					put_pixel(&game->environnement, n, middle - (i), color);
					color = *(int *)(game->east.addr + (int)(i * ratio + TILE / 2) * game->east.line + offset * 4);
					put_pixel(&game->environnement, n, middle + i, color);
				}
			}
			else
			{
				if (game->ray.angle >= PI_90 && game->ray.angle < PI_270)
				{
					if (temp < ANIMATION / 4)
					{
						color = *(int *)(game->north_a[0].addr + (int)((size_column - i) * ratio) * game->north_a[0].line + offset * 4);
						// if (ray_dist / 2 <= 10)
							// printf("ray_dist = %f\n", ray_dist / 2);
						put_pixel(&game->environnement, n, middle - (i), color);
						color = *(int *)(game->north_a[0].addr + (int)(i * ratio + TILE / 2) * game->north_a[0].line + offset * 4);
						put_pixel(&game->environnement, n, middle + i, color);
					}
					if (temp >= ANIMATION / 4 && temp < ANIMATION / 3)
					{
						color = *(int *)(game->north_a[1].addr + (int)((size_column - i) * ratio) * game->north_a[1].line + offset * 4);
						// if (ray_dist / 2 <= 10)
							// printf("ray_dist = %f\n", ray_dist / 2);
						put_pixel(&game->environnement, n, middle - (i), color);
						color = *(int *)(game->north_a[1].addr + (int)(i * ratio + TILE / 2) * game->north_a[1].line + offset * 4);
						put_pixel(&game->environnement, n, middle + i, color);
					}
					if (temp >= ANIMATION / 3 && temp < ANIMATION / 2)
					{
						color = *(int *)(game->north_a[2].addr + (int)((size_column - i) * ratio) * game->north_a[2].line + offset * 4);
						// if (ray_dist / 2 <= 10)
							// printf("ray_dist = %f\n", ray_dist / 2);
						put_pixel(&game->environnement, n, middle - (i), color);
						color = *(int *)(game->north_a[2].addr + (int)(i * ratio + TILE / 2) * game->north_a[2].line + offset * 4);
						put_pixel(&game->environnement, n, middle + i, color);
					}
					if (temp >= ANIMATION / 2 && temp < ANIMATION)
					{
						color = *(int *)(game->north_a[3].addr + (int)((size_column - i) * ratio) * game->north_a[3].line + offset * 4);
						// if (ray_dist / 2 <= 10)
							// printf("ray_dist = %f\n", ray_dist / 2);
						put_pixel(&game->environnement, n, middle - (i), color);
						color = *(int *)(game->north_a[3].addr + (int)(i * ratio + TILE / 2) * game->north_a[3].line + offset * 4);
						put_pixel(&game->environnement, n, middle + i, color);
					}
				}
				else
				{
					color = *(int *)(game->south.addr + (int)((size_column - i) * ratio) * game->south.line + offset * 4);
					// if (ray_dist / 2 <= 10)
						// printf("ray_dist = %f\n", ray_dist / 2);
					put_pixel(&game->environnement, n, middle - (i), color);
					color = *(int *)(game->south.addr + (int)(i * ratio + TILE / 2) * game->south.line + offset * 4);
					put_pixel(&game->environnement, n, middle + i, color);
				}
			}
		}
		else
		{
			put_pixel(&game->environnement, n, middle - i, BLUE);
			put_pixel(&game->environnement, n, middle + i, GREEN);
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
}