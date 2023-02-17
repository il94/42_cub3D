/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/17 03:17:58 by ilandols         ###   ########.fr       */
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
	// printf("offset = %d\n", offset);
	while(i < HEIGHT)
	{
		
		if (i < size_column)
		{
			color = *(int *)(game->wood.addr + i * game->wood.line + offset * 4);
			// put_pixel(&game->environnement, n, middle - i, color);
			// color = *(int *)(game->wood.addr + (TILE - middle - i) * game->wood.line + offset * 4);
			// j = offset / 
			// while (j < size_column)
			{
				// printf("j = %d\n", j);
				put_pixel(&game->environnement, n, middle + i - size_column, color);
				j++;
			}
			// put_pixel(&game->environnement, n, middle - i, color);
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