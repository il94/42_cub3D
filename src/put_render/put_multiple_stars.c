/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_multiple_stars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:00:00 by 32:02 by il       #+#    #+#             */
/*   Updated: 2023/03/11 22:38:51 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static float	get_dir_y(float state)
{
	float		angle;
	static int	i;

	if (i >= 8)
		i = 0;
	angle = state + i * PI_45;
	i++;
	return (state * sin(angle) * STAR_DIST);
}

static float	get_dir_x(float state)
{
	float		angle;
	static int	i;

	if (i >= 8)
		i = 0;
	angle = state + i * PI_45;
	i++;
	return (state * cos(angle) * STAR_DIST);
}

static int	get_pos_y(void)
{
	int			mid;
	int			start;
	static int	i;

	if (i >= 8)
		i = 0;
	mid = HEIGHT / 2;
	if (i == 0 || i == 4)
		start = 0;
	else if (i % 2 == 0)
		start = STAR_START;
	else
		start = STAR_START / 1.5;
	if (i >= 4)
		start *= -1;
	i++;
	return (mid + start);
}

static int	get_pos_x(void)
{
	int			mid;
	int			start;
	static int	i;

	if (i >= 8)
		i = 0;
	mid = WIDTH / 2;
	if (i == 2 || i == 6)
		start = 0;
	else if (i % 2 == 0)
		start = STAR_START;
	else
		start = STAR_START / 1.5;
	if (i >= 2 && i < 6)
		start *= -1;
	i++;
	return (mid + start);
}

void	put_multiple_stars(t_game *game)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		put_image(&game->render, &game->star[0],
			get_pos_x() + get_dir_x(game->star_state),
			get_pos_y() + get_dir_y(game->star_state));
		i++;
	}
	game->star_state += STAR_SPEED;
	if (game->star_state >= 6.28)
	{
		game->stars_apparead = FALSE;
		game->star_state = 0;
	}
}
