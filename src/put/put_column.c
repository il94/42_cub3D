/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:44 by adouay            #+#    #+#             */
/*   Updated: 2023/02/14 20:05:49 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3D.h"

void	put_column(t_game *game, int n)
{
	float	ray_dist;
	float	size;
	int		i;
	int		dif_angle;
	// int		max;
	int		tmp = 0;
	// dif_angle = game->player.angle - game->ray.angle;
	// if (dif_angle < 0)
	// 	dif_angle += (2*M_PI);
	ray_dist = hypotenus(game->player.px_x, game->player.px_y, game->ray.px.x, game->ray.px.y);
	size = HEIGHT / ray_dist * TILE;
	i = HEIGHT / 2;
	// max = i + size;
	// printf("I = %d | MAX = %d\n", i, max);
	int	incr = 0;
	// while(incr < HEIGHT)
	// {
	// 	if (incr > (i - size / 2) && incr < (i + size / 2))
	// 	{
	// 		put_pixel(&game->environnement, n, i - incr, RED);
	// 		put_pixel(&game->environnement, n, i + incr, RED);
	// 	}
	// 	else
	// 		put_pixel(&game->environnement, n, incr, GREY);
	// 	// printf("SALUT\n");
	// 	incr++;
	// }

	while(incr < HEIGHT)
	{
		if (incr < size / 2)
		{
			put_pixel(&game->environnement, n, i - incr, PURPLE);
			put_pixel(&game->environnement, n, i + incr, PURPLE);
		}
		else
		{
			put_pixel(&game->environnement, n, i - incr, BLACK);
			put_pixel(&game->environnement, n, i + incr, BLACK);
			
		}
		// printf("SALUT\n");
		incr++;
	}



	// while(incr < size)
	// {
	// 	put_pixel(&game->environnement, n, i - incr, PURPLE);
	// 	put_pixel(&game->environnement, n, i + incr, PURPLE);
	// 	// printf("SALUT\n");
	// 	incr++;
	// }
}