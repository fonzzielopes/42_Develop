/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:23:55 by alopes            #+#    #+#             */
/*   Updated: 2021/02/23 14:47:38 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *first;

	if (!f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		if(!(new  = ft_lstnew ((*f)(lst->content))))
		{
			while (first)
			{
				new = first->next;
				del(lst->content);
				free(lst);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
