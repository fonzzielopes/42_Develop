/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:10:18 by alopes            #+#    #+#             */
/*   Updated: 2021/06/28 17:08:04 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	stack_size(t_stack_overflow *stacks)
{
	size_t	i;

	i = 0;
	while (stacks)
	{
		stacks = stacks->next;
		i++;
	}
	return (i);
}

int  check_sorted(t_stack_overflow *stacks)
{
	t_stack_overflow	*current;

	if (!stacks)
		return (0);
	current = stacks;
	while (current)
	{
		if (!current->prev)
			return (1);
		else if (current->value > current->prev->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack_overflow *sort(t_stack_overflow *stacks, int pile_a_b)
{
	int	size;

	size = (int)stack_size(stacks);
	if (!stacks || !size)
		return (NULL);
	if (check_sorted(stacks))
		return (stacks);
	if (size == 2)
		stacks = sort_2(stacks, pile_a_b);
	return (stacks);
}
