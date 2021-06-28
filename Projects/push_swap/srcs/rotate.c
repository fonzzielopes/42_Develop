/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:32:18 by alopes            #+#    #+#             */
/*   Updated: 2021/06/28 17:57:19 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*rotate_stack(t_stack_overflow *stacks)
{
	t_stack_overflow *temp;

	if (stack_size(stacks) <=1)
		return (stacks);
	temp = last_el(stacks);
	temp->prev->next = NULL;
	temp->prev = stacks->next;
	if (temp->prev)
		temp->prev->next = temp;
	temp->next = stacks;
	stacks->prev = temp;
	stacks = temp;
	return (stacks);
}
