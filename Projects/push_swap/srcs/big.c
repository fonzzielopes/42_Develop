/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:58:06 by alopes            #+#    #+#             */
/*   Updated: 2021/07/05 13:07:05 by alopes           ###   ########.fr       */
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

static int	is_biggest_at_top(t_stack_overflow *stack)
{
	t_stack_overflow	*current;
	int					biggest;

	current = last_el(stack);
	biggest = current->value;
	while (current)
	{
		if (current->value > biggest)
			return (0);
		current = current->prev;
	}
	return (1);
}

t_stack_overflow	*biggest_to_top(t_stack_overflow *stacks, int pile_a_b)
{
	size_t	size;

	size = stack_size(stacks);
	while (!is_biggest_at_top(stacks))
	{
		if (get_big_num_pos(stacks) <= size / 2)
			stacks = stack_command(REVERSE, pile_a_b, stacks);
		else
			stacks = stack_command(ROTATE, pile_a_b, stacks);
	}
	return (stacks);
}
