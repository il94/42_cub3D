/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_map_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:02:03 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/27 00:04:15 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_texture	enum_check(char *tmp)
{
	if (!ft_strncmp(tmp, "NO ", 3))
		return (NO);
	if (!ft_strncmp(tmp, "SO ", 3))
		return (SO);
	if (!ft_strncmp(tmp, "WE ", 3))
		return (WE);
	if (!ft_strncmp(tmp, "EA ", 3))
		return (EA);
	if (!ft_strncmp(tmp, "F ", 2))
		return (F);
	if (!ft_strncmp(tmp, "C ", 2))
		return (C);
	return (ERROR);
}
