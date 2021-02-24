/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:23:55 by alopes            #+#    #+#             */
/*   Updated: 2021/02/23 16:50:41 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *box;

	if (!lst || !f)
		return (NULL);
	box = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			while (box)
			{
				new = box->next;
				del(lst->content);
				free(lst);
				box = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&box, new);
		lst = lst->next;
	}
	return (box);
}
