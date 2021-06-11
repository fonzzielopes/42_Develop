/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:09:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/11 11:46:42 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_isdigit (char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str [i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_maxmin(long num)
{
	if (num < INT_MIN)
		return (0);
	if (num > INT_MAX)
		return (0);
	return (1);
}

/*int	check_doubles(t_stack_overflow *stacks, long a)
{
	t_stack_overflow *stacks;
	long b;

	if (!stacks)
		return (0);
	if (stacks->length < 2)
		return (0);
}*/

long	*check_error(char *argv, t_stack_overflow *stacks)
{
	long	*num;

	if (!check_isdigit(argv))
		return (0);
	num = (long *)malloc(sizeof(long));
	if (!num)
		return (0);
	*num = ft_atoi(argv);
	if (!check_maxmin(*num))
	{
		free(num);
		return (0);
	}
	if (!check_doubles(stacks, *num))
	{
		free (num);
		return (0);
	}
	return (num);
}

void	print_error(t_stack_overflow *stacks, char *str)
{
	ft_putstr("Error\n");
	free (stacks);
	exit(1);
}
