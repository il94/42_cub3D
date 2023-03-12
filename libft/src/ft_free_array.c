/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:58:20 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/12 17:19:44 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_array(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

void	ft_free_array_size(char **elements, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (elements[i])
			free(elements[i]);
		i++;
	}
	free(elements);
}
