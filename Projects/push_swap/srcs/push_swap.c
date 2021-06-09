/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:39:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/09 12:58:02 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main (int argc, char** argv)
{
	t_stack_overflow *stack_a;

	stack_a = 0;

	if (argc != 1)
		stack_a = check_input_value(*argv[1], argc);

	return (0);
}
