/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2523/02/24 21:32:02 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/24 21:56:45 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	put_stars(t_game *game)
{
	static int	tmp;
	int			i;
	int			j;

	if (tmp > 15)
	{
		game->stars_apparead = FALSE;
		tmp = 0;
	}
	i = tmp;
	j = tmp;
	if (game->stars_apparead)
	{
		put_image(&game->render, &game->star, WIDTH / 2 + tmp * 25, HEIGHT / 2 - tmp * 25);
		
		put_image(&game->render, &game->star, WIDTH / 2 + tmp * 25, HEIGHT / 2 + tmp * 25);
		
		put_image(&game->render, &game->star, WIDTH / 2 - tmp * 25, HEIGHT / 2 + tmp * 25);
		
		put_image(&game->render, &game->star, WIDTH / 2 - tmp * 25, HEIGHT / 2 - tmp * 25);

		tmp++;
	}
}
