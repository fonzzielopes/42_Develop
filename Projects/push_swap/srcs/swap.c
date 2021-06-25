/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:40:48 by alopes            #+#    #+#             */
/*   Updated: 2021/06/25 11:34:34 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_stack(t_stack_overflow *stacks)
{
	int	temp;

	if (stack_size(stacks) > 1)
	{
		temp = (stacks)->next->value;
		(stacks)->next->value = (stacks)->value;
		(stacks)->value = temp;
	}
}
