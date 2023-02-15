/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/15 19:34:24 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3D.h"

void	put_column(t_game *game, int n)
{
	float	ray_dist;
	float	size_column;
	int		middle;
	int		i;

	ray_dist = hypotenus(game->player.px, game->ray.px) * cos(game->player.angle - game->ray.angle);
	ray_dist = fabs(TILE / ray_dist * HEIGHT);
	size_column = ray_dist / 2;
	middle = HEIGHT / 2;
	i = 0;
	while(i < HEIGHT)
	{
		if (i < size_column && i >= size_column - 3)
		{
			put_pixel(&game->environnement, n, middle - i, BLACK);
			put_pixel(&game->environnement, n, middle + i, BLACK);
		}
		else if (i < size_column)
		{
			if (game->ray.wall)
			{
				put_pixel(&game->environnement, n, middle - i, BROWN);
				put_pixel(&game->environnement, n, middle + i, BROWN);
			}
			else
			{
				put_pixel(&game->environnement, n, middle - i, D_BROWN);
				put_pixel(&game->environnement, n, middle + i, D_BROWN);
			}
		}
		else
		{
			put_pixel(&game->environnement, n, middle - i, BLUE);
			put_pixel(&game->environnement, n, middle + i, GREEN);
		}
		i++;
	}
}