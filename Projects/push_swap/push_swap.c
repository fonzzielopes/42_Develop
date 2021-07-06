/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:39:32 by alopes            #+#    #+#             */
/*   Updated: 2021/07/06 11:42:03 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_overflow	*stacks;

	if (!check_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	stacks = create_list(argc, argv);
	stacks = sort(stacks, STACK_A);
	free(stacks);
	return (0);
}
