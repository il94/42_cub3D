/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/12 14:30:11 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

float	get_coeff(int y_end, int y_start, int x_end, int x_start)
{
	float	result;

	result = (float)(abs(y_end - y_start)) / (abs(x_end - x_start));
	if (result == INFINITY)
		result = 0;
	return (result);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float	to_rad(float degrees)
{
	return (degrees * (M_PI / 180));
}
