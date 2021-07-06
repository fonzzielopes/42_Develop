/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:04:57 by alopes            #+#    #+#             */
/*   Updated: 2021/06/29 17:40:06 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*first_el(t_stack_overflow *stacks)
{
	if (!stacks)
		return (NULL);
	while (stacks->prev)
		stacks = stacks->prev;
	return (stacks);
}

t_stack_overflow	*last_el(t_stack_overflow *stacks)
{
	t_stack_overflow	*current;

	if (!stacks)
		return (NULL);
	while (stacks->next)
		current = current->next;
	return (current);
}

void	push_stack(t_stack_overflow **send, t_stack_overflow **rec)
{
	t_stack_overflow	*temp;

	if (stack_size(*rec) < 1)
		return ;
	if (!*rec)
	{
		*rec = last_el(*send);
		(*rec)->prev->next = NULL;
		(*rec)->prev = NULL;
		(*rec)->next = NULL;
	}
	else
	{
		temp = last_el(*send);
		if (temp == *send)
			*send = NULL;
		else
			temp->prev->next = NULL;
		temp->prev = last_el(*rec);
		temp->prev->next = temp;
	}
}
