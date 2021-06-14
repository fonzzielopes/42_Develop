/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:15:37 by alopes            #+#    #+#             */
/*   Updated: 2021/06/14 15:15:33 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*init_stacks(void)
{
	t_stack_overflow	*stacks;

	stacks = (t_stack_overflow *) malloc (sizeof(t_stack_overflow));

	stacks->stack_a = 0;
	stacks->stack_b = 0;
	stacks->length = 0;
	return (stacks);
}
