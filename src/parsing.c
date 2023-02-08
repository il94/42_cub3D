/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:24:50 by adouay            #+#    #+#             */
/*   Updated: 2023/02/08 16:52:55 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static t_bool	check_file_format(char *file, int fd)
{
	char	*extension;
	
	if (read(fd, NULL, 0) == -1)
		return (FALSE);
	extension = ft_strcut_right(file, '.');
	if (!extension)
		return (FALSE); // perror ? exit ?
	if (ft_strcmp(extension, "cub"))
	{
		free (extension); // perror ? exit ?
		return (FALSE);
	}
	free (extension);
	return (TRUE);
}


static t_texture	enum_check(char *tmp)
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

static void	check_sprite(t_game *game, char **file_content)
{
	int	i;
	int	index;

	i = 0;
	game->sprite = ft_calloc(sizeof(char *) , (6 + 1));
	// if (!game->sprite)
	// 	"nik";
	index = enum_check(file_content[i]);
	while (file_content[i] && (index != ERROR || file_content[i][0] == '\n'))
	{
		index = enum_check(file_content[i]);
		if (index != ERROR)
		{
			if (!game->sprite[index])
			{
				game->sprite[index] = ft_strdup(file_content[i]);
				// if (!game->sprite[index])
					//free tout exit
				// printf("SPRTIE = %s\n", game->sprite[index]);
			}
			// else
				//free tout car doublon
		}
		i++;
	}
	i = 0;
	while (game->sprite[i])
		i++;
	if (i != 6)
	{
		printf("pas cool\n");
		ft_free_array_size(game->sprite, 7);
	}

	
}

static void	get_map(t_game *game, char **file_content)
{
	int	i;
	int	tmp;

	i = 0;
	while(file_content[i] && file_content[i][0] != '1' && file_content[i][0] != ' ')
		i++;
	tmp = i;
	i = 0;
	while(file_content[i])
		i++;
	game->map = malloc(sizeof(char *) * (i - tmp + 1));
	i = 0;
	while(file_content[tmp])
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

static void parse_map(char **map)
{
	int	i;
	int	j;

	while(map[i])
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

static void	check_map(t_game *game, char **file_content)
{
	get_map(game, file_content);
	parse_map(game->map);
}

void	get_rgb_value(t_game *game, int idx, int target[3])
{
	char	*str;
	char	**values;
	int		i;
	int		value;

	str = ft_strcut_right(game->sprite[idx], ' ');
	// if (!str)
	// 	nik
	values = ft_split(str, ',');
	// if (!values)
	// 	nik
	i = 0;
	// if (ft_get_size_array(values) != 3)
	// 	bimbadoum
	while (i < 3)
	{
		value = ft_atoi(values[i]);
		if (ft_str_isdigit(values[i]))
			target[i] = ft_atoi(values[i]);
		// else
		// {
		// 	saperlipopette
		// }
		// if (game->f_rgb[i] < 0 && game->f_rgb[i] > 255)
		// 	nik
		i++;
	}
	free(str);
	ft_free_array(values);
}

t_bool    parser(t_game *game, int nb_parameters, char *file)
{
	char    **file_content;
	int		fd;

	if (nb_parameters != 1)
		return (FALSE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FALSE); // perror ? exit ?
	if (!check_file_format(file, fd))
	{
		close (fd);	
		return (FALSE);// perror ? exit ?
	}
	file_content = ft_get_file_content(fd);
	//ft_print_array_n(file_content);
	if (!file_content)
	{
		close (fd);	
		return (FALSE);// perror ? exit ?
	}
	check_sprite(game, file_content);
	get_rgb_value(game, 4, game->f_rgb);
	get_rgb_value(game, 5, game->c_rgb);
	// printf("VALUES = %d %d %d\n", game->f_rgb[0], game->f_rgb[1], game->f_rgb[2]);
	// printf("VALUES = %d %d %d\n", game->c_rgb[0], game->c_rgb[1], game->c_rgb[2]);
	// ft_free_array(file_content);
	check_map(game, file_content);
	ft_free_array(game->sprite);
	return (TRUE);
}

/*
sprites path ok :
	rgb color int ok ?
	path ok
map is ok :
	check if directory
	no space close to 0
	.cub ok;

*/

	