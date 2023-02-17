/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:50:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/17 01:00:14 by ilandols         ###   ########.fr       */
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
# define PI_0 0
# define PI_90 M_PI / 2
# define PI_180 M_PI
# define PI_270 3 * M_PI / 2

# define ERROR_MALLOC "Error malloc\n"

# define KEY_ESC 65307

/* QWERTY */
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97

/* AZERTY */
// # define KEY_W 122
// # define KEY_D 100
// # define KEY_S 115
// # define KEY_A 113

# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define BLACK 0x0
# define GREY 0x6E6E6E
# define PURPLE 0xDAABF9
# define WHITE 0xFFFFFF
# define RED 0xFF1A55
# define GREEN 0x31A851
# define BLUE 0x335B96
# define BROWN 0x966F33
# define D_BROWN 0x8b5D2E
# define CYAN 0x00FFFF

# define WIDTH 960
# define HEIGHT 600
# define TILE 48


# define MINIMAP 4 * TILE

# define PLAYER_MINIMAP 9
# define POINT 9

# define FOV 60	
# define ANGLE_PLAYER 90	
# define SPEED 5

typedef enum e_texture{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
}	t_texture;

typedef struct s_fpos{
	float	x;
	float	y;	
}	t_fpos;


typedef struct s_player{
	t_pos	map;
	t_fpos	px;
	t_fpos	dir;
	t_fpos	dir_side;
	float	angle;
}	t_player;

typedef struct s_ray
{
	t_fpos	px;
	t_fpos	offset_h;
	t_fpos	offset_v;
	float	angle;
	t_bool	to_up;
	t_bool	to_left;
	
	int		wall;
}	t_ray;


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
	t_pos		size_map;

	t_ray		ray;
	
	/* temp */
	t_fpos		ray1;
	t_fpos		ray2;
	/**/

    char    	**sprite;
	int			f_rgb[3];
	int			c_rgb[3];
	int			fd;
	char		**file_content;

	t_bool	move_up;
	t_bool	move_right;
	t_bool	move_down;
	t_bool	move_left;
	t_bool	move_dir_left;
	t_bool	move_dir_right;

	t_player	player;

	t_img		render;
	t_img		environnement;
	t_img		minimap;
	t_img		trimmed_minimap;

	t_img		wood;
}   t_game;


/*============================================================================*/

/* free_memory.c */
void	verify_alloc(t_game *game, void *ptr);
void	free_all_elements(t_game *game);
void    free_all_and_exit(t_game *game, char *str_error);

/* process_inputs */
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
void	process_inputs(t_game *game);

/* utils.c */
float	correc_angle(float angle);
float	hypotenus(t_fpos start, t_fpos end);
float	get_coeff(int y_end, int y_start, int x_end, int x_start);
void	swap(float *a, float *b);
float	to_rad(float degrees);

/* run.c */
int		run(t_game *game);


/*============================================================================*/

/* put_environnement.c */
void	put_column(t_game *game, int n);
void	put_environnement(t_game *game);

/* put_trimmed_minimap.c */
void	put_trimmed_minimap(t_game *game);

/* draw_minimap.c */
void	put_direction_line(t_game *game);
void	draw_minimap(t_game *game);

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

/* temp.c */
void	put_vertical_line(t_game *game, int y_start);
void	put_line(t_game *game, t_fpos start, t_fpos end, double coeff);
void	put_direction_line(t_game *game);
void	put_raycasting_minimap(t_game *game, float angle, t_fpos ray);
void	put_point(t_game *game, int x, int y, int color);
void	print_ray(t_ray ray);

#endif