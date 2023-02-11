/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:53:26 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/11 16:48:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_array_sprite_content(t_game *game)
{
	int	i;

	i = 0;
	while (game->sprite[i])
		i++;
	if (i != 6)
		free_all_and_exit(game, "Missing informations\n");
}

void	check_sprite(t_game *game, char **file_content)
{
	int	i;
	int	index;

	i = 0;
	game->sprite = ft_calloc(sizeof(char *), (6 + 1));
	verify_alloc(game, game->sprite);
	index = enum_check(file_content[i]);
	while (file_content[i] && (index != ERROR || file_content[i][0] == '\n'))
	{
		index = enum_check(file_content[i]);
		if (index != ERROR)
		{
			if (!game->sprite[index])
			{
				game->sprite[index] = ft_strdup(file_content[i]);
				verify_alloc(game, game->sprite[index]);
			}
			else
				free_all_and_exit(game, "Doublon\n");
		}
		i++;
	}
	check_array_sprite_content(game);
}

static void	assign_rgb_value(t_game *game, char **values, int trgt[3])
{
	int	i;
	int	value;

	i = 0;
	while (i < 3)
	{
		value = ft_atoi(values[i]);
		if (ft_str_isdigit(values[i]) && value >= 0 && value <= 255)
			trgt[i] = value;
		else
		{
			ft_free_array(values);
			free_all_and_exit(game, "RGB value is invalid\n");
		}
		i++;
	}
}

void	get_rgb_value(t_game *game, int idx, int target[3])
{
	char	**values;

	values = ft_split(game->sprite[idx], ", CF\n");
	verify_alloc(game, values);
	if (ft_get_size_array(values) != 3)
	{
		ft_free_array(values);
		free_all_and_exit(game, "RGB value is invalid 1\n");
	}
	assign_rgb_value(game, values, target);
	ft_free_array(values);
}
