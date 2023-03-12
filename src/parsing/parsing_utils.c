/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:54:56 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/12 18:09:07 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	dup_line_into_map(t_game *game, int tmp)
{
	int	i;

	i = 0;
	while (game->file_content[tmp])
	{
		game->map[i] = ft_strdup(game->file_content[tmp]);
		verify_alloc(game, game->map[i]);
		if (game->map[i][ft_strlen(game->map[i]) - 1]
			&& game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
		tmp++;
	}
	game->map[i] = 0;
}

void	get_map(t_game *game, char **file_content, int start)
{
	int	i;

	i = 0;
	while (file_content[i])
		i++;
	game->map = malloc(sizeof(char *) * (i - start + 1));
	verify_alloc(game, game->map);
	dup_line_into_map(game, start);
}

void	check_file_format(t_game *game, char *file)
{
	char	*extension;

	if (read(game->fd, NULL, 0) == -1)
		free_all_and_exit(game, "ERROR : Is not a file\n");
	extension = ft_strcut_right(file, '.');
	if (!extension)
		free_all_and_exit(game, ERROR_MALLOC);
	if (ft_strcmp(extension, "cub"))
	{
		free (extension);
		free_all_and_exit(game, "ERROR : .cub extension required\n");
	}
	free (extension);
}
