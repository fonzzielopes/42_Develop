/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:45:27 by alopes            #+#    #+#             */
/*   Updated: 2021/07/05 13:01:17 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	filling(t_stack_overflow **stacks, t_stack_overflow **helper, int *arr,
				int partition)
{
	int	i;
	int	closest;
	int	num_at_top;
	int	directly_below;

	i = 0;
	while (i < partition)
	{
		closest = from_arr_closest_to_top(*stacks, arr, partition);
		*stacks = get_num_to_top(closest, *stacks, STACK_A);
		num_at_top = last_el(*stacks)->value;
		if (*helper)
		{
			directly_below = get_directly_below(*helper, num_at_top);
			*helper = get_num_to_top(directly_below, *helper, STACK_B);
		}
		run_push(STACK_A, stacks, helper);
		i++;
	}
}

static void	copy_remaining_to_helper(t_stack_overflow **stacks, t_stack_overflow **helper,
				int pile_a_b)
{
	int	num_at_top;
	int	directly_below;

	while (stack_size(*stacks))
	{
		num_at_top = last_el(*stacks)->value;
		if (*helper)
		{
			directly_below = get_directly_below(*helper, num_at_top);
			*helper = get_num_to_top(directly_below, *helper, !pile_a_b);
		}
		run_push(pile_a_b, stacks, helper);
	}
}

t_stack_overflow	*parsing_sort(t_stack_overflow *stacks, int pile_a_b,
						int partition)
{
	int		*arr;
	t_stack_overflow	*helper;

	helper = NULL;
	arr = malloc(partition * sizeof(int));
	while (stack_size(stacks) > (size_t)partition)
	{
		fill_smallest(arr, stacks, partition);
		filling(&stacks, &helper, arr, partition);
	}
	free(arr);
	copy_remaining_to_helper(&stacks, &helper, pile_a_b);
	helper = biggest_to_top(helper, !pile_a_b);
	while (helper)
		run_push(!pile_a_b, &helper, &stacks);
	return (stacks);
}
