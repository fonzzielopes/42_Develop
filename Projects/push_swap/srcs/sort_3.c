/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:12:56 by alopes            #+#    #+#             */
/*   Updated: 2021/07/06 11:07:39 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	get_big_num_pos(t_stack_overflow *stacks)
{
	t_stack_overflow	*current;
	size_t	pos;
	size_t	big_num_pos;
	int		big_num;

	pos = 1;
	current = stacks;
	big_num = current->value;
	big_num_pos = pos;
	while (current)
	{
		if (current->value > big_num)
		{
			big_num = current->value;
			big_num_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (big_num_pos);
}

t_stack_overflow	*sort_3(t_stack_overflow *stacks, int pile_a_b)
{
	size_t	big_num_pos;

	if (check_sorted(stacks))
		return (stacks);
	big_num_pos = get_big_num_pos(stacks);
	if (big_num_pos == 3)
	{
		stacks = stack_command(ROTATE, pile_a_b, stacks);
		stacks = sort_2(stacks, pile_a_b);
	}
	else if (big_num_pos == 2)
	{
		stacks = stack_command(REVERSE, pile_a_b, stacks);
		if (!check_sorted(stacks))
			stacks = stack_command(SWAP, pile_a_b, stacks);
	}
	else if (big_num_pos == 1)
		stacks = sort_2(stacks, pile_a_b);
	return (stacks);
}
