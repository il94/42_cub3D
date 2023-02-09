/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:19 by adouay            #+#    #+#             */
/*   Updated: 2023/02/09 19:16:45 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_game_struct(t_game *src)
{
	src->mlx_ptr = NULL;
	src->win_ptr = NULL;
	src->fd = -1;
	src->sprite = NULL;
	src->file_content = NULL;
	src->map = NULL;


	src->move_up = FALSE;
	src->move_right = FALSE;
	src->move_down = FALSE;
	src->move_left = FALSE;

}
