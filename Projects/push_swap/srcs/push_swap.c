/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:39:32 by alopes            #+#    #+#             */
/*   Updated: 2021/09/14 12:21:22 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_asign_arg_order2(int *args, int *order, char **argv, int argc)
{
	int	i;

	i = 0;
	while (argv && i < argc - 1 && ft_atoi_long(argv[i]) >= -2147483648
		&& ft_atoi_long(argv[i]) < 2147483648)
	{
		args[i] = (int)ft_atoi_long(argv[i]);
		order[i] = args[i];
		i++;
	}
	ft_free_split(argv);
	return (i + 1);
}

int	ft_asign_arg_order(int *args, int *order, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc && ft_atoi_long(argv[i]) >= -2147483648
		&& ft_atoi_long(argv[i]) < 2147483648)
	{
		args[i - 1] = (int)ft_atoi_long(argv[i]);
		order[i - 1] = args[i - 1];
		i++;
	}
	return (i);
}

void	ft_choose_algo(t_list *stack_a, int argc)
{
	if (ft_is_ordered(stack_a))
		return ;
	else if (argc < 27)
		ft_sort_small(&stack_a, argc - 1);
	else
		ft_radix_sort(&stack_a, ft_max_len(stack_a), argc - 1);
}

int	main(int argc, char **argv)
{
	int		*args;
	int		*order;
	int		argcx;
	t_list	*stack_a;

	argcx = argc;
	if (argc == 1 || !argv[1] || !ft_nword(argv[1], ' '))
		return (0);
	if (argc == 2)
		argc = ft_nword(argv[1], ' ') + 1;
	args = malloc(sizeof(int) * (argc - 1));
	order = malloc(sizeof(int) * (argc - 1));
	if ((argcx == 2 && ft_asign_arg_order2(args, order, ft_split(argv[1], ' '),
				argc) < argc) || (argcx > 2 && ft_asign_arg_order(args, order,
				argv, argc) < argc) || ft_check_repeat(args, argc - 1))
	{
		ft_free_array(args, order);
		return (write(1, "Error\n", 6));
	}
	stack_a = ft_initialize_stack(&args, &order, argc - 1);
	ft_choose_algo(stack_a, argc);
	ft_free_stack(&stack_a);
	return (0);
}
