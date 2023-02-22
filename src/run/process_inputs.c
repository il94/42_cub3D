/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:10 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/22 18:38:25 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	move_player(t_game *game, float x, float y)
{
	t_pos	target;
	t_pos	old_pos_map;

	old_pos_map = game->player.map;
	target.x = x / TILE;
	target.y = y / TILE;
	if (game->map[game->player.map.y][target.x] == '0'
		|| game->map[game->player.map.y][target.x] == '3'
		|| check_player_carac(game->map[game->player.map.y][target.x]))
		game->player.px.x = x;
	if (game->map[target.y][game->player.map.x] == '0'
		|| game->map[target.y][game->player.map.x] == '3'
		|| check_player_carac(game->map[target.y][game->player.map.x]))
		game->player.px.y = y;
	if (game->map[(int)game->player.px.y / TILE]
		[(int)game->player.px.x / TILE] != '1')
	{
		game->player.map.x = game->player.px.x / TILE;
		game->player.map.y = game->player.px.y / TILE;
	}
	if (old_pos_map.x != game->player.map.x
		|| old_pos_map.y != game->player.map.y)
		if (game->map[old_pos_map.y][old_pos_map.x] == '3')
		{
			system("cvlc sounds/close_bar.wav &");
			game->map[old_pos_map.y][old_pos_map.x] = '2';
		}
}

void	process_inputs(t_game *game)
{	
	if (game->move_dir_left)
		game->player.angle = correc_angle(game->player.angle + SENSI_KEY);
	if (game->move_dir_right)
		game->player.angle = correc_angle(game->player.angle - SENSI_KEY);
	game->player.dir.x = cos(game->player.angle) * SPEED;
	game->player.dir.y = -sin(game->player.angle) * SPEED;
	game->player.dir_side.x = cos(game->player.angle + to_rad(90)) * SPEED;
	game->player.dir_side.y = -sin(game->player.angle + to_rad(90)) * SPEED;
	if (game->move_up)
		move_player(game, game->player.px.x + game->player.dir.x,
			game->player.px.y + game->player.dir.y);
	if (game->move_right)
		move_player(game, game->player.px.x - game->player.dir_side.x,
			game->player.px.y - game->player.dir_side.y);
	if (game->move_down)
		move_player(game, game->player.px.x - game->player.dir.x,
			game->player.px.y - game->player.dir.y);
	if (game->move_left)
		move_player(game, game->player.px.x + game->player.dir_side.x,
			game->player.px.y + game->player.dir_side.y);
}

int	mouse_move(int x, int y, t_game *game)
{	
	if (game->mouse_on)
	{
		if (x < game->mouse.x)
			game->player.angle = correc_angle(game->player.angle + SENSI_MOUSE);
		else if (x > game->mouse.x)
			game->player.angle = correc_angle(game->player.angle - SENSI_MOUSE);
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, WIDTH / 2, HEIGHT / 2);
	}
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
	else if (keycode == KEY_SPACE)
		open_door(game);
	else if (keycode == KEY_TAB)
		game->mouse_on = !game->mouse_on;
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
