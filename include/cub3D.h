/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:50:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/10 15:05:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../mlx_linux/mlx.h"
# include "../libft/include/libft.h"

# define _USE_MATH_DEFINES

# define ERROR_MALLOC "Error malloc\n"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97

# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define BLACK 0x0
# define GREY 0x6E6E6E
# define PURPLE 0xDAABF9
# define WHITE 0xFFFFFF

# define WIDTH 2560
# define HEIGHT 1440

# define W_MINIMAP WIDTH / 4
# define H_MINIMAP HEIGHT / 4

typedef enum e_texture{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
}	t_texture;

typedef struct s_player{
	int		map_x;
	int		map_y;
	float	px_x;
	float	px_y;
	float	dir_x;
	float	dir_y;
	float	angle;
}	t_player;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		end;
	int		width;
	int		height;
}				t_img;

typedef struct s_game{
    void    	*mlx_ptr;
    void   		*win_ptr;

	t_player	player;

    char    	**map;
	t_img		minimap;

    char    	**sprite;
	int			f_rgb[3];
	int			c_rgb[3];

	int		fd;
	char	**file_content;

	t_bool	move_up;
	t_bool	move_right;
	t_bool	move_down;
	t_bool	move_left;





	
}   t_game;


/* run.c */
int	run(t_game *game);

/* put_render.c */
void	put_render(t_game *game);

/* input_keyboard.c */
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);

/* init_mlx.c */
void	init_mlx(t_game *game);

/* parsing_utils.c */
int			check_space_around(char **map, int i, int j);
int			check_player_carac(char c);
void		check_file_format(t_game *game, char *file);
t_texture	enum_check(char *tmp);

/* parsing_map.c */
void	parse_map(t_game *game);
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