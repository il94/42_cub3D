/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:00:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/11/13 18:12:39 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_delete_char(char *str, size_t index)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	if (index >= ft_strlen(str))
		return (str);
	result = malloc(ft_strlen(str) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str && str[j])
	{
		if (j == index)
			j++;
		if (!str[j])
			break ;
		result[i++] = str[j++];
	}
	result[i] = '\0';
	return (result);
}
