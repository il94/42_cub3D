/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrrncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:04:01 by ilandols          #+#    #+#             */
/*   Updated: 2022/12/07 17:39:49 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_lists.h"

t_list2	*ft_lststrrncmp_lex(t_list2 **lst, char *to_find)
{
	t_list2	*tmp;	
	char	*to_find_cut;

	tmp = *lst;
	while (tmp)
	{
		to_find_cut = ft_strcut_right(tmp->content, '=');
		if (!to_find_cut)
			exit (456);
		if (!ft_strrncmp(to_find, to_find_cut, ft_strlen(to_find_cut)))
		{
			free(to_find_cut);
			return (tmp);
		}
		tmp = tmp->next;
		free(to_find_cut);
	}
	return (NULL);
}
