/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:24:50 by adouay            #+#    #+#             */
/*   Updated: 2023/02/08 19:29:02 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	parser(t_game *game, int nb_parameters, char *file)
{
	char	**file_content;
	int		fd;

	if (nb_parameters != 1)
		free_all_and_exit(game, "No or too many arguments\n");
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		free_all_and_exit(game, "Invalid file\n");
	check_file_format(game, file);
	file_content = ft_get_file_content(game->fd);
	// ft_print_array_n(file_content);
	verify_alloc(game, file_content);
	check_sprite(game, file_content);
	get_rgb_value(game, 4, game->f_rgb);
	get_rgb_value(game, 5, game->c_rgb);
	check_map(game, file_content);
	ft_free_array(file_content);
}

/*
sprites path ok :
	path ok
map is ok :
	no space close to 0
*/