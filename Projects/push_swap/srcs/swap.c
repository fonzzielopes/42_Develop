/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:40:48 by alopes            #+#    #+#             */
/*   Updated: 2021/06/30 16:50:53 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*swap_stack(t_stack_overflow *stacks)
{
	t_stack_overflow	*current;
	int		temp;

	if (stack_size(stacks) <= 1)
	{
		return (stacks);
	}
	current = last_el(stacks);
	temp = current->value;
	current->value = current->prev->value;
	current->prev->value = temp;
	return (stacks);
}
