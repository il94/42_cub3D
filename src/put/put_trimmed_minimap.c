/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_trimmed_minimap.c                                  :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:11:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/16 17:46:09 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	put_new_player(t_game *game)
{
	int	x;
	int	y;

	y = MINIMAP / 2 - PLAYER_MINIMAP / 2;
	while (y < PLAYER_MINIMAP * 2)
	{
		x = MINIMAP / 2 - PLAYER_MINIMAP / 2;
		while (x < PLAYER_MINIMAP * 2)
		{
			put_pixel(&game->new_minimap, x + TILE * 2, y + TILE * 2, PURPLE);
			x++;
		}
		y++;
	}
}

void	put_trimmed_minimap(t_game *game)
{
	t_pos	start;
	t_pos	tmp;
	int	x;
	int	y;
	int	color;
	start.y = game->player.px.y - TILE * 2;

	y = 0;
	while (y < game->player.px.y + TILE * 2 + TILE)
	{
		x = 0;
		start.x = game->player.px.x - TILE * 2;
		while (x < game->player.px.x + TILE * 2 + TILE)
		{
			if (x == 0 || x == MINIMAP - 1 || y == 0 || y == MINIMAP - 1)
				put_pixel(&game->new_minimap, x, y, BLACK);
			else if (start.x < 0 || start.y < 0 || start.x >= game->size_map.x || start.y >= game->size_map.y)
				put_pixel(&game->new_minimap, x, y, BLUE);
			else
			{
				color = *(int *)(game->minimap.addr + start.y * game->minimap.line + start.x * 4);
				put_pixel(&game->new_minimap, x, y, color);
			}
			x++;
			start.x++;
		}
		y++;
		start.y++;
	}
	put_point(game, MINIMAP / 2, MINIMAP / 2, PURPLE);
	put_raycasting_minimap(game, game->player.angle + to_rad(FOV / 2), game->ray1);
	put_raycasting_minimap(game, game->player.angle - to_rad(FOV / 2), game->ray2);
	put_image(&game->render, &game->new_minimap, TILE, TILE);

}