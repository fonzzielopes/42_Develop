/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:04:57 by alopes            #+#    #+#             */
/*   Updated: 2021/09/15 11:51:53 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returns the minimum number of stack_a that is not sorted, as the new limit.

void	ft_merge(t_list **stack_a, t_list **stack_b, int *min,
	int *max)
{
	write(1, "pa\n", 3);
	ft_push(stack_b, stack_a);
	if ((*stack_a)->index < *min)
		*min = (*stack_a)->index;
	else
	{
		write(1, "ra\n", 3);
		*max = (*stack_a)->index;
		ft_rotate(stack_a);
	}
}
