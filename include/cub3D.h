/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:50:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/12 16:45:02 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include <X11/extensions/Xfixes.h>

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/include/libft.h"

# define _USE_MATH_DEFINES
# define PI_0 0
# define PI_45 0.785398163397448309615
# define PI_90 1.57079632679489661923
# define PI_270 4.71238898038468985769

# define ERROR_MALLOC "Error malloc\n"

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

# define KEY_ESC 65307
# define KEY_SPACE 32
# define KEY_TAB 65289

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

# define SKY 0x072533

# define TILE 128
# define WIDTH 960
# define HEIGHT 600

# define MNMP_TILE 48
# define MINIMAP 192 // 4 * MNMP_TILE

# define FOV 60	
# define SPEED 5
# define SENSI_KEY 0.05
# define SENSI_MOUSE 0.02

# define SCROLLING 512000

# define STAR_START 150
# define STAR_DIST 75
# define STAR_SPEED 0.2

# define POINT 9

typedef enum e_texture{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
}	t_text;

typedef struct s_fpos{
	float		x;
	float		y;	
}	t_fpos;

typedef struct s_player{
	t_pos		map;
	t_fpos		px;
	t_fpos		dir;
	t_fpos		dir_side;
	float		angle;
}	t_player;

typedef struct s_ray
{
	t_fpos		px;
	t_fpos		offset_h;
	t_fpos		offset_v;
	float		angle;
	t_bool		up;
	t_bool		left;

	t_bool		wall_h;
	t_bool		wall_v;
}	t_ray;

typedef struct s_myimg {
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			end;
	int			width;
	int			height;
}				t_mimg;

typedef struct s_game{
	t_xvar		*mlx_ptr;
	t_win_list	*win_ptr;

	char		**map;
	t_pos		size_map;
	char		**sprite;
	int			f_color;
	int			c_color;
	int			fd;
	char		**file_content;

	t_pos		mouse;

	t_bool		move_up;
	t_bool		move_right;
	t_bool		move_down;
	t_bool		move_left;
	t_bool		move_dir_left;
	t_bool		move_dir_right;
	t_bool		mouse_on;

	t_ray		ray;
	t_ray		ray_first;
	t_ray		ray_last;
	t_ray		ray_mid;

	t_player	player;

	t_mimg		render;
	t_mimg		environnement;
	t_mimg		full_minimap;
	t_mimg		minimap;

	t_mimg		north;
	t_mimg		south;
	t_mimg		west;
	t_mimg		east;

	t_mimg		sky;
	t_bool		image_sky;

	t_mimg		star[3];
	t_bool		stars_apparead;
	t_bool		is_door;
	float		star_state;

}	t_game;

/*============================================================================*/

/* free_memory.c */
void	verify_alloc(t_game *game, void *ptr);
void	free_all_elements(t_game *game);
void	free_all_and_exit(t_game *game, char *str_error);

/* process_inputs */
void	process_inputs(t_game *game);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);

/* utils.c */
float	correc_angle(float angle);
float	hypotenus(t_fpos start, t_fpos end);
float	get_coeff(int y_end, int y_start, int x_end, int x_start);
void	swap(float *a, float *b);
float	to_rad(float degrees);

/* run.c */
int		run(t_game *game);

/*============================================================================*/

/* draw_minimap.c */
void	draw_minimap(t_game *game);

/* put_column.c*/
void	put_column(t_game *game, t_mimg *to_print, float ray_dist, int n);
void	put_column_anim(t_game *game, t_mimg *to_print, float ray_dist, int n);

/* put_environnement_utils.c*/
void	init_offset(t_game *game);
t_bool	is_vertical_wall(char **map, t_fpos src, t_bool to_right);
t_bool	is_horizontal_wall(char **map, t_fpos src, t_bool to_right);
t_fpos	init_start_v(t_game *game);
t_fpos	init_start_h(t_game *game);

/* put_environnement.c */
void	put_environnement(t_game *game);

/* put_minimap.c */
void	put_minimap(t_game *game);

/* put_sky.c */
void	put_sky_image(t_game *game);
void	put_sky_color(t_game *game);

/* put_multiple_stars.c */
void	put_multiple_stars(t_game *game);

/* put_utils.c */
t_mimg	*get_image(t_game *game);
int		get_color(t_mimg *src, int x, int y);
void	put_pixel(t_mimg *dst_myimg, int x, int y, int color);
void	put_line(t_game *game, t_fpos start, t_fpos end, double coeff);
void	put_image(t_mimg *dst_myimg, t_mimg *src_img, int x, int y);

/* put_render.c */
void	put_render(t_game *game);

/*============================================================================*/

/* parsing_data_map_utils.c */
t_text	enum_check(char *tmp);

/* parsing_data_map.c */
int		check_sprite(t_game *game, char **file_content);
int		get_color_to_rgb(t_game *game, char *rgb_code, t_bool color_sky);

/* parsing_map_utils.c */
int		valid_carac(int c);
int		check_player_carac(char c);
int		check_space_around(char **map, int i, int j);

/* parsing_map.c */
void	check_map(t_game *game, char **file_content, int start);

/* parsing_utils.c */
void	dup_line_into_map(t_game *game, int tmp);
void	get_map(t_game *game, char **file_content, int start);
void	check_file_format(t_game *game, char *file);

/* parsing.c */
void	parser(t_game *game, int nb_parameters, char *file);

/*============================================================================*/

/* door.c */
void	close_door(t_game *game, t_pos old_pos_map);
void	near_door(t_game *game);
void	open_door(t_game *game);

/* move.c */
int		move_mouse(int x, int y, t_game *game);
void	move_player(t_game *game, float x, float y);

/*============================================================================*/

/* init_mlx.c */
void	init_mlx(t_game *game);

/* init_utils.c */
void	*new_get_data_addr(t_game *game, t_mimg *sprite);
void	*new_mlx_new_image(t_game *game, t_mimg *sprite, int width, int height);
void	*new_xpm_to_image(t_game *game, t_mimg *sprite, char *path);

/* init/init.c */
void	init(t_game *src);

/*============================================================================*/

/* main.c */
int		main(int ac, char **av);

#endif
