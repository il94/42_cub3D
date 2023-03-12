/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:56:58 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/12 18:42:45 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
			if ((map[i][j] == '0' || map[i][j] == '2' || map[i][j] == '3'
				|| check_player_carac(map[i][j])) && n != 0)
				free_all_and_exit(game, "ERROR : Invalid map\n");
			else if (map[i][j] == '1' && n > 3)
				free_all_and_exit(game, "ERROR : Invalid map\n");
			j++;
		}
		i++;
	}
}

static void	get_player_info(t_game *game, int i, int j)
{
	game->player.map.x = j;
	game->player.map.y = i;
	game->player.px.x = j * TILE + TILE / 2;
	game->player.px.y = i * TILE + TILE / 2;
	if (game->map[i][j] == 'N')
		game->player.angle = to_rad(90);
	if (game->map[i][j] == 'S')
		game->player.angle = to_rad(270);
	if (game->map[i][j] == 'W')
		game->player.angle = to_rad(180);
	if (game->map[i][j] == 'E')
		game->player.angle = to_rad(0);
}

static void	check_carac(t_game *game, char **map)
{
	t_pos	i;
	int		n;

	i.y = 0;
	n = 0;
	while (map[i.y])
	{
		i.x = 0;
		while (map[i.y][i.x])
		{
			if (!valid_carac(map[i.y][i.x]))
			{
				if (!check_player_carac(map[i.y][i.x]))
					free_all_and_exit(game, "ERROR : Invalid carac\n");
				get_player_info (game, i.y, i.x);
				n++;
			}
			i.x++;
		}
		if (i.x == 0)
			free_all_and_exit(game, "ERROR : Empty line in map\n");
		i.y++;
	}
	if (n != 1)
		free_all_and_exit(game, "ERROR : Need only one player\n");
}

static t_pos	get_size_map(char **map)
{
	t_pos	result;
	int		i;
	int		size;

	i = 0;
	result.x = 0;
	result.y = ft_get_size_array(map);
	while (i < result.y)
	{
		size = ft_strlen(map[i]);
		if (result.x < size)
			result.x = size;
		i++;
	}
	result.x *= TILE;
	result.y *= TILE;
	return (result);
}

void	check_map(t_game *game, char **file_content, int start)
{
	get_map(game, file_content, start);
	check_carac(game, game->map);
	check_map_surended_wall(game, game->map);
	game->size_map = get_size_map(game->map);
}
