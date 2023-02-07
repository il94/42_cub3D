/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:14:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/09/01 00:14:16 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

# include "../../../include/libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_list2
{
	void			*content;
	struct s_list2	*next;
	struct s_list2	*prev;
}					t_list2;

t_list2		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list2 *lst);
t_list2		*ft_lstlast(t_list2 *lst);
void		ft_lstadd_back(t_list2 **lst, t_list2 *new);
void		ft_lstdelone(t_list2 *lst);
void		ft_lstclear(t_list2 **lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list2		*ft_lstmap(t_list2 *lst, void *(*f)(void *), void (*del)(void *));
int			ft_lstis_correct(t_list2 *lst, int size);
void		ft_lstprint(t_list2 *lst);
t_list2		*ft_lstsplit_charset(char const *s, char *charset);
t_list2		*ft_array_to_lst(char **array);
t_list2		*ft_lstnew_dup(void *content);
void		ft_lstclear_dup(t_list2 **lst);
t_list2		*ft_lststrncmp_lex(t_list2 **lst, char *to_find, int n);
t_list2		*ft_lststrrncmp_lex(t_list2 **lst, char *to_find);

#endif