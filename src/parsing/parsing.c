/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:24:50 by adouay            #+#    #+#             */
/*   Updated: 2023/02/24 21:13:37 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	parser(t_game *game, int nb_parameters, char *file)
{
	if (nb_parameters != 1)
		free_all_and_exit(game, "No or too many arguments\n");
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		free_all_and_exit(game, "Invalid file\n");
	check_file_format(game, file);
	game->file_content = ft_get_file_content(game->fd);
	verify_alloc(game, game->file_content);
	check_sprite(game, game->file_content);
	game->f_color = get_color_to_rgb(game, game->sprite[F], 0);
	game->c_color = get_color_to_rgb(game, game->sprite[C], 1);
	check_map(game, game->file_content);
}
