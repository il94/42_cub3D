/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/15 16:29:02 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

float	correc_angle(float angle)
{
	float	result;

	if (angle > (2 * M_PI))
		result = angle - (2 * M_PI);
	else if (angle < 0)
		result = angle + (2 * M_PI);
	else
		result = angle;
	return (result);
}

float	hypotenus(t_fpos start, t_fpos end)
{
	return (sqrt(((start.x - end.x) * (start.x - end.x)) + ((start.y - end.y) * (start.y - end.y))));
}

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
