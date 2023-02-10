/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:49:50 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/10 14:00:23 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	// printf("PI = %f\n", M_PI);

    // double angle;

    // printf( "Veuillez saisir un angle en radian : " );
    // scanf( "%lf", &angle );

    // printf( "Le cosinus de l'angle vaut : %lf\n", cos( angle ) );
    // printf( "Le sinus de l'angle vaut : %lf\n", sin( angle ) );
    // printf( "La tangente de l'angle vaut : %lf\n", tan( angle ) );




	
	init_game_struct(&game);
	parser(&game, ac - 1, av[1]);
	init_mlx(&game);
	free_all_elements(&game);
	return (0);
}
