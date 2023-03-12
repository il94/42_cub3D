/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap.c                                  :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:11:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/16 17:46:09 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	put_minimap_ray(t_game *game, float angle, t_fpos ray)
{
	t_fpos	start;
	t_fpos	end;
	t_fpos	tmp1;
	t_fpos	tmp2;

	tmp1.x = (MNMP_TILE * game->player.px.x / TILE);
	tmp1.y = (MNMP_TILE * game->player.px.y / TILE);
	tmp2.x = (MNMP_TILE * ray.x / TILE);
	tmp2.y = (MNMP_TILE * ray.y / TILE);
	start.x = MINIMAP / 2;
	start.y = MINIMAP / 2;
	end.x = MINIMAP / 2 + (cos(angle) * hypotenus(tmp1, tmp2));
	end.y = MINIMAP / 2 + (-sin(angle) * hypotenus(tmp1, tmp2));
	if (start.x > end.x)
	{
		swap(&start.x, &end.x);
		swap(&start.y, &end.y);
	}
	put_line(game, start, end, get_coeff(end.y, start.y, end.x, start.x));
}

static void	put_point(t_game *game, int x, int y, int color)
{
	int	x_index;
	int	y_index;

	x_index = x - (POINT / 2);
	while (x_index < x + (POINT / 2))
	{
		y_index = y - (POINT / 2);
		while (y_index < y + (POINT / 2))
		{
			put_pixel(&game->minimap, x_index, y_index, color);
			y_index++;
		}
		x_index++;
	}
}

static	t_bool	is_outside_map(t_game *game, t_pos start)
{
	t_pos	target;

	target.x = start.x / MNMP_TILE;
	target.y = start.y / MNMP_TILE;
	if (start.y < 0 || start.y >= MNMP_TILE * game->size_map.y / TILE)
		return (TRUE);
	else if (start.x < 0 || target.x > ft_strlen(game->map[target.y]))
		return (TRUE);
	else if (!game->map[target.y][target.x]
		|| game->map[target.y][target.x] == ' ')
	{
		if (start.x % MNMP_TILE == 0 && game->map[target.y][target.x - 1] == '1'
			&& start.x < game->size_map.x)
			return (FALSE);
		else if (start.y % MNMP_TILE == 0 && target.y > 0
			&& game->map[target.y - 1][target.x] == '1')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

static void	put_minimap_line(t_game *game, t_pos start, int y)
{
	int	x;

	x = 0;
	start.x = (MNMP_TILE * (game->player.px.x / TILE)) - MNMP_TILE * 2;
	while (x < (MNMP_TILE * (game->player.px.x / TILE)) + MNMP_TILE * 3)
	{
		if (x == 0 || x == MINIMAP - 1 || y == 0 || y == MINIMAP - 1)
			put_pixel(&game->minimap, x, y, BLACK);
		else if (is_outside_map(game, start))
			put_pixel(&game->minimap, x, y, game->c_color);
		else
			put_pixel(&game->minimap, x, y,
				get_color(&game->full_minimap, start.y, start.x));
		x++;
		start.x++;
	}
}

void	put_minimap(t_game *game)
{
	t_pos	start;
	int		y;

	start.y = (MNMP_TILE * (game->player.px.y / TILE)) - MNMP_TILE * 2;
	y = 0;
	while (y < (MNMP_TILE * (game->player.px.y / TILE)) + MNMP_TILE * 3)
	{
		put_minimap_line(game, start, y);
		y++;
		start.y++;
	}
	put_point(game, MINIMAP / 2, MINIMAP / 2, PURPLE);
	put_minimap_ray(game, game->player.angle + to_rad(FOV / 2),
		game->ray_first.px);
	put_minimap_ray(game, game->player.angle - to_rad(FOV / 2),
		game->ray_last.px);
	put_image(&game->render, &game->minimap, MNMP_TILE, MNMP_TILE);
}
