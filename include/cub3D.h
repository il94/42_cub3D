/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:50:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/07 18:16:28 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#include "../libft/include/libft.h"

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
    char    **map;
}   t_game;


/* parsing.c */
t_bool    parser(t_game *game, int nb_parameters, char *file);


/* initiatlisation.c */
void	init_game_struct(t_game *src);


/* main.c */
int	main(int ac, char **av);

#endif