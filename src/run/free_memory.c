/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:25:47 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/24 21:13:57 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	verify_alloc(t_game *game, void *ptr)
{
	if (!ptr)
		free_all_and_exit(game, ERROR_MALLOC);
}

static void	new_mlx_destroy_image(t_game *game, t_img *sprite)
{
	if (sprite->img)
		mlx_destroy_image(game->mlx_ptr, sprite->img);
}

static void	destroy_mlx_images(t_game *game)
{
	new_mlx_destroy_image(game, &game->star);
	new_mlx_destroy_image(game, &game->sky);
	new_mlx_destroy_image(game, &game->west);
	new_mlx_destroy_image(game, &game->east);
	new_mlx_destroy_image(game, &game->south);
	new_mlx_destroy_image(game, &game->north);
	new_mlx_destroy_image(game, &game->minimap);
	new_mlx_destroy_image(game, &game->full_minimap);
	new_mlx_destroy_image(game, &game->environnement);
	new_mlx_destroy_image(game, &game->render);
}

void	free_all_elements(t_game *game)
{
	system("pkill vlc");
	destroy_mlx_images(game);
	if (game->fd != -1)
		close(game->fd);
	if (game->sprite)
		ft_free_array_size(game->sprite, 7);
	if (game->file_content)
		ft_free_array(game->file_content);
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

void	free_all_and_exit(t_game *game, char *str_error)
{
	free_all_elements(game);
	if (str_error)
		perror(str_error);
	exit(EXIT_FAILURE);
}
