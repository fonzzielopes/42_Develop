/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:39:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/16 17:49:53 by alopes           ###   ########.fr       */
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
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	stacks = create_list(argc, argv);
	free(stacks);
	return (0);
}
