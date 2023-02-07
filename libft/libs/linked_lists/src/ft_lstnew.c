/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:43:31 by ilyes             #+#    #+#             */
/*   Updated: 2022/12/06 16:20:38 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_lists.h"

t_list2	*ft_lstnew_dup(void *content)
{
	t_list2	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = ft_strdup(content);
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

t_list2	*ft_lstnew(void *content)
{
	t_list2	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}
