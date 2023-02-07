/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:02:33 by ilandols          #+#    #+#             */
/*   Updated: 2022/12/07 17:39:23 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_lists.h"

t_list2	*ft_array_to_lst(char **array)
{
	t_list2	*lst;
	t_list2	*new;
	int		i;

	i = 0;
	lst = NULL;
	while (array && array[i])
	{
		new = ft_lstnew_dup(array[i]);
		if (!new || !new->content)
		{
			ft_lstclear(&lst);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}
