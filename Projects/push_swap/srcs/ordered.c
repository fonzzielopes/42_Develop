/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:04:56 by amorion-          #+#    #+#             */
/*   Updated: 2021/09/14 11:17:51 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_ordered(t_list *stack)
{
	t_list	*ptr;

	ptr = stack;
	while (ptr->next && ptr->next->index - ptr->index == 1)
		ptr = ptr->next;
	if (ptr->next)
		return (0);
	return (1);
}

int	ft_max_len(t_list *stack_a)
{
	int		max;
	t_list	*ptr;

	ptr = stack_a;
	max = ptr->len;
	while (ptr)
	{
		if (ptr->len > max)
			max = ptr->len;
		ptr = ptr->next;
	}
	return (max);
}

void	ft_push_b(t_list **stack_a, t_list **stack_b, int i, int size)
{
	t_list	*ptr;
	int		mark;

	mark = 0;
	ptr = *stack_a;
	while (mark < size)
	{
		if (i > ptr->len || ptr->binary[ptr->len - i] == '0')
		{
			ft_push(stack_a, stack_b);
			write(1, "pb\n", 3);
			ptr = *stack_a;
		}
		else
		{
			write(1, "ra\n", 3);
			ft_rotate(stack_a);
			ptr = *stack_a;
		}
		mark++;
	}
}

void	ft_radix_sort(t_list **stack_a, int maxlen, int size)
{
	t_list	*ptr;
	t_list	**stack_b;
	int		i;
	int		mark;

	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		exit(1);
	*stack_b = NULL;
	mark = 0;
	i = 1;
	while (i <= maxlen)
	{
		ft_push_b(stack_a, stack_b, i, size);
		ptr = *stack_b;
		while (ptr)
		{
			ft_push(stack_b, stack_a);
			write(1, "pa\n", 3);
			ptr = *stack_b;
		}
		i++;
	}
	free(stack_b);
}
