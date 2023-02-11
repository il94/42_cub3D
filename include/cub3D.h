/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:50:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/11 21:18:58 by ilandols         ###   ########.fr       */
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
# define RED 0xFF1A55

# define WIDTH 2560
# define HEIGHT 1440

# define W_MINIMAP WIDTH / 4
# define H_MINIMAP HEIGHT / 4
# define TILE 48
# define PLAYER_MINIMAP 9

# define FOV 80 //a definir

typedef enum e_texture{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
}	t_texture;

// typedef struct s_pos{
// 	float	x;
// 	float	y;	
// }	t_pos;


typedef struct s_player{
	int		map_x;
	int		map_y;
	float	px_x;
	float	px_y;
	float	angle;
	float	dir_x;
	float	dir_y;
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

    char    	**map;
    char    	**sprite;
	int			f_rgb[3];
	int			c_rgb[3];
	int			fd;
	char		**file_content;

	t_bool	move_up;
	t_bool	move_right;
	t_bool	move_down;
	t_bool	move_left;

	t_player	player;
	
	t_img		render;
	t_img		minimap;
}   t_game;


/*============================================================================*/

/* free_memory.c */
void	verify_alloc(t_game *game, void *ptr);
void	free_all_elements(t_game *game);
void    free_all_and_exit(t_game *game, char *str_error);

/* input_keyboard.c */
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);

/* utils.c */
float	get_coeff(int y_end, int y_start, int x_end, int x_start);
void	swap(int *a, int *b);
float	to_rad(float degrees);

/* run.c */
void	move_player(t_game *game);
int		run(t_game *game);

/*============================================================================*/

/* put_minimap.c */
void	put_minimap(t_game *game);

/* put_utils.c */
void	put_pixel(t_img *dst_img, int x, int y, int color);
void	put_image(t_img *dst_img, t_img *src_img, int x, int y);

/* put_render.c */
void	put_render(t_game *game);

/*============================================================================*/

/* parsing_data_map.c */
void	check_sprite(t_game *game, char **file_content);
void	get_rgb_value(t_game *game, int idx, int target[3]);

/* parsing_map.c */
void	check_map(t_game *game, char **file_content);

/* parsing_utils.c */
int			check_space_around(char **map, int i, int j);
int			check_player_carac(char c);
void		check_file_format(t_game *game, char *file);
t_texture	enum_check(char *tmp);

/* parsing.c */
void    parser(t_game *game, int nb_parameters, char *file);

/*============================================================================*/

/* init/init.c */
void	init(t_game *src);

/* init_mlx.c */
void	init_mlx(t_game *game);

/*============================================================================*/

/* main.c */
int	main(int ac, char **av);

#endif