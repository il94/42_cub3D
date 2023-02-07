/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:58:20 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/07 19:35:41 by adouay           ###   ########.fr       */
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