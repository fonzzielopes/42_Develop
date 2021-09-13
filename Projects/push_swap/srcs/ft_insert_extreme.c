/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_extreme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:04:57 by alopes            #+#    #+#             */
/*   Updated: 2021/09/13 11:09:07 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_insert_extreme(t_list **stack_a, t_list **stack_b, int *min,
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
