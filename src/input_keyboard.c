/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:45:10 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/09 15:48:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx_ptr);
	return (0);
}
