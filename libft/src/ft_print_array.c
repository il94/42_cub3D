/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:56:06 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/08 14:43:45 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_print_array(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		ft_printf("%s\n", elements[i]);
		i++;
	}
}

void	ft_print_array_n(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		ft_printf("%s", elements[i]);
		i++;
	}
}