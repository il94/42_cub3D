/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:56:58 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/08 17:58:27 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	get_map(t_game *game, char **file_content)
{
	int	i;
	int	tmp;

	i = 0;
	while (file_content[i] && file_content[i][0] != '1'
		&& file_content[i][0] != ' ')
		i++;
	tmp = i;
	i = 0;
	while (file_content[i])
		i++;
	game->map = malloc(sizeof(char *) * (i - tmp + 1));
	i = 0;
	while (file_content[tmp])
	{
		game->map[i] = ft_strdup(file_content[tmp]);
		i++;
		tmp++;
	}
	game->map[i] = 0;
	ft_print_array_n(game->map);
}

static int	check_player_carac(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static void	parse_map(char **map)
{
	int	i;
	int	j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				if (map[i][j + 1] && map[i][j + 1] == '\n')
					return ; //exit error parse
					//printf("sal\n");
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != '\n')
			{
				if (!check_player_carac(map[i][j]))
					return ; //exit error parse
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game, char **file_content)
{
	get_map(game, file_content);
	parse_map(game->map);
}