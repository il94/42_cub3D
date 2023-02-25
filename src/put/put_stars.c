/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: SPEED_STARS23/02/24 21:32:02 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/24 23:48:26 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"


int	ft_fibonacci(int index)
{
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	else if (index < 0)
	{
		return (-1);
	}
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

#define SPEED_STARS 5

void	put_stars(t_game *game)
{
	static int		DISTANCE;
	static int		TEMP;
	static int		TIME;
	static float	t;

	if (TIME > 512000)
		TIME = 0;

	if (TIME % 5 == 0)
		DISTANCE++;

	if (t >= 6.28)
		t = 0;
	if (game->stars_apparead)
	{
		put_image(&game->render, &game->star, WIDTH / 2 +  t * cos(t) * 30, HEIGHT / 2 + t * sin(t) * 30);
		put_image(&game->render, &game->star, WIDTH / 2 +  t * cos(t + PI_90) * 30, HEIGHT / 2 + t * sin(t + PI_90) * 30);
		put_image(&game->render, &game->star, WIDTH / 2 +  t * cos(t + M_PI) * 30, HEIGHT / 2 +  t * sin(t + M_PI) * 30);
		put_image(&game->render, &game->star, WIDTH / 2 +  t * cos(t + PI_270) * 30, HEIGHT / 2 +  t * sin(t + PI_270) * 30);
		t += 0.1;
	}
	TIME++;
	if (DISTANCE > 16)
	{
		game->stars_apparead = FALSE;
		DISTANCE = 0;
		TIME = 0;
		t = 0;
	}
}
