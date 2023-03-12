/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:02:01 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/12 17:41:45 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	valid_carac(int c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == ' ')
		return (1);
	return (0);
}

int	check_player_carac(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_space_around(char **map, int i, int j)
{
	int	n;

	n = 0;
	if (j == 0 || (!map[i][j - 1] || map[i][j - 1] == ' '))
		n++;
	if (j == (ft_strlen(map[i]) - 1) || (!map[i][j + 1]
		|| map[i][j + 1] == ' '))
		n++;
	if (i == 0 || j >= ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
		n++;
	if (i == (ft_get_size_array(map) - 1) || j >= ft_strlen(map[i + 1])
		|| map[i + 1][j] == ' ')
		n++;
	return (n);
}
