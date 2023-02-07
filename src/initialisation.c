/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:19 by adouay            #+#    #+#             */
/*   Updated: 2023/02/07 18:22:36 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_game_struct(t_game *src)
{
	src->mlx_ptr = NULL;
	src->win_ptr = NULL;
	// src->sprite = NULL;
	// src->map = NULL;
}
