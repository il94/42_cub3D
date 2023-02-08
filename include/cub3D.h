/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:50:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/08 17:58:36 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#include "../mlx_linux/mlx.h"
#include "../libft/include/libft.h"

#define ERROR_MALLOC "Error malloc\n"

typedef enum e_texture{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
}	t_texture;

typedef struct s_game{
    void    *mlx_ptr;
    void    *win_ptr;
    char    **sprite;
	int		f_rgb[3];
	int		c_rgb[3];
	int		fd;
    char    **map;
}   t_game;


/* parsing_utils.c */
void		check_file_format(t_game *game, char *file);
t_texture	enum_check(char *tmp);

/* parsing_map.c */
void	check_map(t_game *game, char **file_content);

/* parsing_data_map.c */
void	check_sprite(t_game *game, char **file_content);
void	get_rgb_value(t_game *game, int idx, int target[3]);

/* parsing.c */
void    parser(t_game *game, int nb_parameters, char *file);

/* free_memory.c */
void	verify_alloc(t_game *game, void *ptr);
void	free_all_elements(t_game *game);
void    free_all_and_exit(t_game *game, char *str_error);


/* initiatlisation.c */
void	init_game_struct(t_game *src);


/* main.c */
int	main(int ac, char **av);

#endif