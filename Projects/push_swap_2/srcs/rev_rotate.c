/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:01:49 by alopes            #+#    #+#             */
/*   Updated: 2021/06/29 17:41:08 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*rev_rotate_stack(t_stack_overflow *stacks)
{
	t_stack_overflow	*temp;

	if (stack_size(stacks) <= 1)
		return (stacks);
	temp = stacks->next;
	temp->prev = stacks->prev;
	if (temp->prev)
		temp->prev->next = temp;
	stacks->next = NULL;
	stacks->prev = last_el(temp);
	stacks->prev->next = stacks;
	stacks = temp;
	return (stacks);
}
