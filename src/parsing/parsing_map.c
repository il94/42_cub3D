/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:56:58 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/14 20:05:40 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	dup_line_into_map(t_game *game, int tmp)
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

static void	check_map_surended_wall(t_game *game, char **map)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			n = check_space_around(map, i, j);
			if ((map[i][j] == '0' || check_player_carac(map[i][j])) && n != 0)
				free_all_and_exit(game, "Invalid map\n");
			else if (map[i][j] == '1' && n > 3)
				free_all_and_exit(game, "Invalid map\n");
			j++;
		}
		i++;
	}
}

static void	get_player_info(t_game *game, int i, int j)
{
	game->player.map_x = j;
	game->player.map_y = i;
	game->player.px_x = j * TILE + TILE / 2;
	game->player.px_y = i * TILE + TILE / 2;
}

static void	check_carac(t_game *game, char **map)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ')
			{
				if (!check_player_carac(map[i][j]))
					free_all_and_exit(game, "Parsing Error : Invalide carac\n");
				get_player_info (game, i, j);
				n++;
			}
			j++;
		}
		if (j == 0)
			free_all_and_exit(game, "Parsing Error : Empty line in map\n");
		i++;
	}
	if (n != 1)
		free_all_and_exit(game, "Need only one player\n");
}

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
	verify_alloc(game, game->map);
	dup_line_into_map(game, tmp);
}

void	check_map(t_game *game, char **file_content)
{
	get_map(game, file_content);
	check_carac(game, game->map);
	check_map_surended_wall(game, game->map);
}
