/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:00:12 by alopes            #+#    #+#             */
/*   Updated: 2021/07/05 12:09:10 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_smallest(t_stack_overflow *stack, int *arr, int partition)
{
	t_stack_overflow	*current;
	int		temp;

	temp = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->value < temp && !is_in(current->value, arr, partition))
			temp = current->value;
		current = current->next;
	}
	return (temp);
}

void	fill_smallest(int *arr, t_stack_overflow *stacks, int partition)
{
	int	i;

	i = 0;
	while (i < partition)
		arr[i++] = INT_MIN;
	i = 0;
	while (i < partition)
	{
		arr[i] = get_smallest(stacks, arr, partition);
		i++;
	}
}
