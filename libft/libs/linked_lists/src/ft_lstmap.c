/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:30:43 by ilyes             #+#    #+#             */
/*   Updated: 2022/12/07 17:38:34 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_lists.h"

t_list2	*ft_lstmap(t_list2 *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list2	*new;
	t_list2	*li;

	li = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			while (li)
			{
				new = li->next;
				(*del)(li->content);
				free(li);
				li = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&li, new);
		lst = lst->next;
	}
	return (li);
}
