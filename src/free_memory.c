/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:25:47 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/08 16:42:37 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_all_elements(t_game *game)
{
	if (game->sprite)
		ft_free_array_size(game->sprite, 7);
	if (game->map)
		ft_free_array(game->map);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

void    free_all_and_exit(t_game *game, char *str_error)
{
	free_all_elements(game);
	if (str_error)
		perror(str_error);
	exit(EXIT_FAILURE);
}