/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:31:39 by alopes            #+#    #+#             */
/*   Updated: 2021/06/30 18:36:41 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*sort_2(t_stack_overflow *stacks, int pile_a_b)
{
	t_stack_overflow	*first;
	t_stack_overflow	*last;

	if (check_sorted(stacks))
		return (stacks);
	last = last_el(stacks);
	first = last->prev;
	if (last->value > first->value)
		stacks = stack_command(SWAP, pile_a_b, stacks);
	return (stacks);
}
