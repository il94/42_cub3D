/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/17 16:52:44 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3D.h"

void	put_column(t_game *game, int n)
{
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

	if (game->ray.wall == 0) // horizontal
		offset = (int)game->ray.px.x % TILE;
	else
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
			color = *(int *)(game->north.addr + (int)((size_column - i) * ratio) * game->north.line + offset * 4);
			// if (ray_dist / 2 <= 10)
				// printf("ray_dist = %f\n", ray_dist / 2);
			put_pixel(&game->environnement, n, middle - (i), color);
			color = *(int *)(game->north.addr + (int)(i * ratio + TILE / 2) * game->north.line + offset * 4);
			put_pixel(&game->environnement, n, middle + i, color);
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
}