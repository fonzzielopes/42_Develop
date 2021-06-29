/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:31:39 by alopes            #+#    #+#             */
/*   Updated: 2021/06/29 15:54:15 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*sort_2(t_stack_overflow *stacks, int pile_a_b)
{
	t_stack_overflow	*i;
	t_stack_overflow	*j;

	if (check_sorted(stacks))
		return (stacks);
	j = last_el(stacks);
	i = j->prev;
	if (j->value > i->value)
		stacks = stack_command(SWAP, stacks, pile_a_b);
	return (stacks);
}
