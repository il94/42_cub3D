/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:10 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/14 18:28:24 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	move_player(t_game *game, int x, int y)
{
	if (game->map[y / TILE][x / TILE] == '0'
		|| game->map[y / TILE][x / TILE] == 'N')
	{
		game->player.px_x = x;
		game->player.px_y = y;
	}
	if (game->player.map_x != x / TILE || game->player.map_y != y / TILE)
	{
		game->player.map_x = x / TILE;
		game->player.map_y = y / TILE;
	}
}

void	process_inputs(t_game *game)
{
	// if (game->move_up)
	// 	move_player(game, game->player.px_x + game->player.dir_x, game->player.px_y + game->player.dir_y);
	// if (game->move_right)
	// 	move_player(game, game->player.px_x - fabs(game->player.dir_x), game->player.px_y - fabs(game->player.dir_y));
	// if (game->move_down)
	// 	move_player(game, game->player.px_x - game->player.dir_x, game->player.px_y - game->player.dir_y);
	// if (game->move_left)
	// 	move_player(game, game->player.px_x + fabs(game->player.dir_x), game->player.px_y + fabs(game->player.dir_y));
	
	if (game->move_up)
		move_player(game, game->player.px_x, game->player.px_y - 5);
	if (game->move_right)
		move_player(game, game->player.px_x + 5, game->player.px_y);
	if (game->move_down)
		move_player(game, game->player.px_x, game->player.px_y + 5);
	if (game->move_left)
		move_player(game, game->player.px_x - 5, game->player.px_y);
	if (game->move_dir_left)
	{
		game->player.angle += 0.1;
		if (game->player.angle > (2 * M_PI))
			game->player.angle -= (2 * M_PI);
	}
	if (game->move_dir_right)
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle += (2 * M_PI);
	 }
	game->player.dir_x = cos(game->player.angle) * MAX_MINIMAP;
	game->player.dir_y = -sin(game->player.angle) * MAX_MINIMAP;
	// game->player.dir_x = cos(game->player.angle) * 5;
	// game->player.dir_y = -sin(game->player.angle) * 5;
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move_up = FALSE;
	else if (keycode == KEY_D)
		game->move_right = FALSE;
	else if (keycode == KEY_S)
		game->move_down = FALSE;
	else if (keycode == KEY_A)
		game->move_left = FALSE;
	else if (keycode == KEY_LEFT)
		game->move_dir_left = FALSE;
	else if (keycode == KEY_RIGHT)
		game->move_dir_right = FALSE;
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move_up = TRUE;
	else if (keycode == KEY_D)
		game->move_right = TRUE;
	else if (keycode == KEY_S)
		game->move_down = TRUE;
	else if (keycode == KEY_A)
		game->move_left = TRUE;
	else if (keycode == KEY_LEFT)
		game->move_dir_left = TRUE;
	else if (keycode == KEY_RIGHT)
		game->move_dir_right = TRUE;
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx_ptr);
	return (0);
}
