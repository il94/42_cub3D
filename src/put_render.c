/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/11 21:03:43 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

#define PLAYER_MINIMAP 9
void    draw_player(t_game *game)
{
    int    x;  //pos en px
    int    y;  //pos en px

    x = game->player.px_x - (PLAYER_MINIMAP / 2);

    while (x < game->player.px_x + (PLAYER_MINIMAP / 2))
    {
        y = game->player.px_y - (PLAYER_MINIMAP / 2);
        while (y < game->player.px_y + (PLAYER_MINIMAP / 2))
        {
			if (x == game->player.px_x && y == game->player.px_y)
				my_mlx_pixel_put(&game->minimap, x + (int)game->player.dir_x, y +(int)game->player.dir_y, PURPLE);
            my_mlx_pixel_put(&game->minimap, x, y, PURPLE);
            y++;    
        }
        x++;
    }
}

// void	draw_player(t_game *game, int color, int x, int y)
// {
// 	int	x_tile;
// 	int	y_tile;

// 	y_tile = 0;
// 	while (y_tile < 50)
// 	{
// 		x_tile = 0;
// 		while (x_tile < 50)
// 		{
// 			if (x_tile >= 21 && x_tile <= 29 && y_tile >= 21 && y_tile <= 29)
// 				my_mlx_pixel_put(&game->minimap, x + x_tile, y + y_tile, color);
// 			if (x_tile == 25 && y_tile == 25)
// 				my_mlx_pixel_put(&game->minimap, x + x_tile + (int) game->player.dir_x, y + y_tile + (int)game->player.dir_y, color);
// 			x_tile++;
// 		}
// 		y_tile++;
// 	}
// }


void	draw_tile(t_game *game, int color, int x, int y)
{
	int	x_tile;
	int	y_tile;

	y_tile = 0;
	while (y_tile < 50)
	{
		x_tile = 0;
		while (x_tile < 50)
		{
			if (x_tile < 1 || x_tile > 49 || y_tile < 1 || y_tile > 49)
				my_mlx_pixel_put(&game->minimap, x + x_tile, y + y_tile, BLACK);
			else
				my_mlx_pixel_put(&game->minimap, x + x_tile, y + y_tile, color);
			x_tile++;
		}
		y_tile++;
	}
}

void	put_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || check_player_carac(game->map[y][x]))
				draw_tile(game, WHITE, x * 50, y * 50);
			else if (game->map[y][x] == '1')
				draw_tile(game, GREY, x * 50, y * 50);
			else
				draw_tile(game, BLACK, x * 50, y * 50);			
			x++;
		}
		y++;
	}
	draw_player(game);
}

void	put_render(t_game *game)
{
	put_minimap(game);
	cast_ray_v(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->minimap.img, 0, 0);
}