/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:04:57 by alopes            #+#    #+#             */
/*   Updated: 2021/06/25 12:13:09 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_overflow	*first_el(t_stack_overflow *stacks)
{
	if (!stacks)
		return (NULL);
	while (stacks->prev)
		stacks = stacks->prev;
	return (stacks);
}
