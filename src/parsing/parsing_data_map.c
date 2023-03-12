/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:53:26 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/12 17:32:50 by ilandols         ###   ########.fr       */
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
		free_all_and_exit(game, "ERROR : Missing informations\n");
}

static char	*get_sprite_path(t_game *game, char *str)
{
	char	*result;

	result = ft_strcut_right(str, ' ');
	verify_alloc(game, &str);
	result = ft_strcut_left_free(result, '\n');
	verify_alloc(game, &str);
	return (result);
}

int	check_sprite(t_game *game, char **file_content)
{
	int		i;
	int		index;

	i = 0;
	game->sprite = ft_calloc(sizeof(char *), (6 + 1));
	verify_alloc(game, game->sprite);
	index = enum_check(file_content[i]);
	while (file_content[i] && (index != ERROR || file_content[i][0] == '\n'))
	{
		if (index != ERROR)
		{
			if (!game->sprite[index])
				game->sprite[index] = get_sprite_path(game, file_content[i]);
			else
				free_all_and_exit(game, "ERROR : Doublon\n");
		}
		i++;
		index = enum_check(file_content[i]);
	}
	check_array_sprite_content(game);
	return (i);
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
			free_all_and_exit(game, "ERROR : Invalid RGB value\n");
		}
		i++;
	}
}

int	get_color_to_rgb(t_game *game, char *rgb_code, t_bool color_sky)
{
	char	**values;
	int		rgb[3];
	int		result;

	values = ft_split(rgb_code, ", CF\n");
	verify_alloc(game, values);
	if (ft_get_size_array(values) != 3)
	{
		ft_free_array(values);
		values = NULL;
		if (!color_sky)
			free_all_and_exit(game, "ERROR : Invalid RGB value\n");
		else
		{
			game->image_sky = TRUE;
			return (SKY);
		}
	}
	if (values)
	{
		assign_rgb_value(game, values, rgb);
		ft_free_array(values);
	}
	result = rgb[0] * 65536 + rgb[1] * 256 + rgb[2];
	return (result);
}
