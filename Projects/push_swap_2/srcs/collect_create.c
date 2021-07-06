/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:15:37 by alopes            #+#    #+#             */
/*   Updated: 2021/06/25 10:04:11 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack_overflow	*new_info(int value)
{
	t_stack_overflow	*pile;

	pile = malloc(sizeof(t_stack_overflow));
	if (!pile)
		return (NULL);
	pile->value = value;
	pile->prev = NULL;
	pile->next = NULL;
	return (pile);
}

static t_stack_overflow	*init_stacks(int *info, size_t size)
{
	t_stack_overflow	*stacks;
	t_stack_overflow	*current;
	size_t				i;

	stacks = new_info(info[0]);
	current = stacks;
	i = 1;
	while (i < size)
	{
		current->next = new_info(info[i]);
		if (!current->next)
			return (0);
		current->next->prev = current;
		current = current->next;
		i++;
	}
	return (stacks);
}

t_stack_overflow	*create_list(int argc, char **argv)
{
	t_stack_overflow	*stacks;
	int					*list;
	int					size;
	int					i;

	size = argc - 1;
	list = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		list[i] = ft_atoi(argv[size - i]);
		i++;
	}
	stacks = init_stacks(list, size);
	return (stacks);
}
