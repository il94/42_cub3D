/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:54:56 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/08 17:59:40 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	check_file_format(t_game *game, char *file)
{
	char	*extension;

	if (read(game->fd, NULL, 0) == -1)
		free_all_and_exit(game, "Is not a file\n");
	extension = ft_strcut_right(file, '.');
	if (!extension)
		free_all_and_exit(game, ERROR_MALLOC);
	if (ft_strcmp(extension, "cub"))
	{
		free (extension);
		free_all_and_exit(game, ".cub extension required\n");
	}
	free (extension);
}

t_texture	enum_check(char *tmp)
{
	if (!ft_strncmp(tmp, "NO ", 3))
		return (NO);
	if (!ft_strncmp(tmp, "SO ", 3))
		return (SO);
	if (!ft_strncmp(tmp, "WE ", 3))
		return (WE);
	if (!ft_strncmp(tmp, "EA ", 3))
		return (EA);
	if (!ft_strncmp(tmp, "F ", 2))
		return (F);
	if (!ft_strncmp(tmp, "C ", 2))
		return (C);
	return (ERROR);
}
