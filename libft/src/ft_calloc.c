/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:44:23 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/07 18:22:09 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*p;
	char		*c;

	if (nmemb == 0 || size == 0)
		p = malloc(1);
	else
		p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	c = p;
	ft_bzero(c, nmemb * size);
	return (p);
}
