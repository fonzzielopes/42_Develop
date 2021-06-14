/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:39:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/14 15:18:55 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_overflow	*stacks;

	if (argc == 1)
		return (1);
	if (!check_error(argv))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	stacks = init_stacks();
	free(stacks);
	return (0);
}
