/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:56:58 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/08 20:32:57 by adouay           ###   ########.fr       */
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
		if (game->map[i][ft_strlen(game->map[i]) - 1] && game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
		tmp++;
	}
	game->map[i] = 0;
	ft_print_array(game->map);
}

static int	check_player_carac(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static void	check_carac(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ')
			{
				if (!check_player_carac(map[i][j]))
					free_all_and_exit(game, "Parsing Error : Invalide carac\n");
			}
			j++;
		}
		if (j == 0)
				free_all_and_exit(game, "Parsing Error : Empty line in map\n");
		i++;
	}
}

static int	check_space_around(char **map, int i, int j)
{
	int	n;
	
	n = 0;
	if (j == 0 || (!map[i][j - 1] || map[i][j - 1] == ' '))
		n++;
	if (j == (ft_strlen(map[i]) - 1) || (!map[i][j + 1] || map[i][j + 1] == ' '))
		n++;
	if (i == 0 || (!map[i - 1][j] || map[i - 1][j] == ' '))
		n++;
	if (i == (ft_get_size_array(map) - 1) || (!map[i + 1][j] || map[i + 1][j] == ' '))
		n++;
	// printf("I = %d | J = %d | N = %d\n", i, j, n);
	return (n);
}

// static int	check_space_around(char **map, int i, int j)
// {
// 	int	n;
	
// 	n = 0;
// 	if (j != 0 && (map[i][j - 1] == ' ' || !map[i][j - 1]))
// 		n++;
// 	if (j != (ft_strlen(map[i]) - 1) && (map[i][j + 1] == ' ' || !map[i][j + 1]))
// 		n++;
// 	if (i != 0 &&(map[i - 1][j] == ' ' || !map[i - 1][j]))
// 		n++;
// 	if (i != (ft_get_size_array(map) - 1) && (map[i + 1][j] == ' ' || !map[i + 1][j]))
// 		n++;
// 	printf("I = %d | J = %d | N = %d\n", i, j, n);
// 	return (n);
// }

static void check_map_surended_wall(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || j == 0 || j == (ft_strlen(map[i]) - 1) || i == (ft_get_size_array(map) - 1))
					free_all_and_exit(game, "Invalid map\n");
				if (check_space_around(map, i, j))
					free_all_and_exit(game, "Invalid map\n");
			}
			if (check_player_carac(map[i][j]))
				if (check_space_around(map, i, j))
					free_all_and_exit(game, "Invalid map\n");
			if (map[i][j] == '1')
				if (check_space_around(map, i, j) > 3)
					free_all_and_exit(game, "Invalid map\n");
			j++;
		}
		i++;
	}
}

void	parse_map(t_game *game)
{
	check_carac(game, game->map);
	check_map_surended_wall(game, game->map);	
}

void	check_map(t_game *game, char **file_content)
{
	get_map(game, file_content);
	parse_map(game);
}