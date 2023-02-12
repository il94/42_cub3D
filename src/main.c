/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:49:50 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/12 15:41:19 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	// printf("VAL = %f\n", M_PI - M_PI);
	// printf("VAL = %f\n", M_PI / 2);
	// printf("VAL = %f\n", M_PI);
	// printf("VAL = %f\n", 3 * M_PI / 2);
	// printf("VAL = %f\n", M_PI * 2);

	init(&game);
	parser(&game, ac - 1, av[1]);
	init_mlx(&game);
	free_all_elements(&game);
	return (0);
}
