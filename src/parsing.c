/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:24:50 by adouay            #+#    #+#             */
/*   Updated: 2023/02/07 18:23:03 by adouay           ###   ########.fr       */
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

// static t_texture	enum_check(char *tmp)
// {
// 	if (!ft_strcmp(tmp, "NO"))
// 		return (NO);
// 	if (!ft_strcmp(tmp, "SO"))
// 		return (SO);
// 	if (!ft_strcmp(tmp, "WE"))
// 		return (WE);
// 	if (!ft_strcmp(tmp, "EA"))
// 		return (EA);
// 	if (!ft_strcmp(tmp, "F"))
// 		return (F);
// 	if (!ft_strcmp(tmp, "C"))
// 		return (C);
// 	return (ERROR);
// }

// static void	check_sprite(t_game *game, char **file_content)
// {
// 	int	i;
// 	char *tmp;

// 	i = 0;
// 	game->sprite = malloc(sizeof(char *) * 6);
// 	// if (!game->sprite)
// 	// 	"nik";
// 	tmp = NULL;
// 	while (file_content[i])
// 	{
// 		// printf("LINE = %s\n", file_content[i]);
// 		tmp = ft_strcut_left(file_content[i], ' ');
// 		// if (!tmp)
// 			// "nik";
// 		if (enum_check(tmp) != ERROR)
// 		{
// 			game->sprite[enum_check(tmp)] = file_content[i];
// 			printf("SPRTIE = %s\n", game->sprite[enum_check(tmp)]);
// 		}
// 		else if (file_content[i][0] != '\n')
// 			break ;
// 		free(tmp);
// 		i++;
// 	}
// 	free(tmp);

// 	// sprite[NO] = mafonctiontahlesofus("NO ", 3);
// }

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
				printf("SPRTIE = %s\n", game->sprite[index]);
			}
			// else
				//free tout car doublon
		}
		i++;
	}
	ft_free_array(game->sprite);
	// sprite[NO] = mafonctiontahlesofus("NO ", 3);
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
	if (!file_content)
	{
		close (fd);	
		return (FALSE);// perror ? exit ?
	}
	check_sprite(game, file_content);
	ft_free_array(file_content);
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

	