/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:03:14 by ilandols          #+#    #+#             */
/*   Updated: 2022/12/07 17:39:32 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_lists.h"

t_list2	*ft_lststrncmp_lex(t_list2 **lst, char *to_find, int n)
{
	t_list2	*tmp;	

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, to_find, n))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
