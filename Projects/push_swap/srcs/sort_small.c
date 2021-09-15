/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:31:39 by alopes            #+#    #+#             */
/*   Updated: 2021/09/15 10:25:25 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3_b(t_list **stack)
{
	if ((*stack)->index < (*stack)->next->next->index
		&& (*stack)->next->index < (*stack)->next->next->index)
		return ;
	else if ((*stack)->index < (*stack)->next->next->index)
	{
		write(1, "sa\n", 3);
		ft_swap(stack);
		write(1, "ra\n", 3);
		ft_rotate(stack);
	}
	else
	{
		write(1, "rra\n", 4);
		ft_rev_rotate(stack);
	}
}

/*
** This function sorts stack_a of size less than 3. Only three types of
** instructions are used: rra, ra, sa.
*/

void	ft_sort_3(t_list **stack)
{
	if ((*stack)->index < (*stack)->next->index)
		ft_sort_3_b(stack);
	else if ((*stack)->index > (*stack)->next->next->index)
	{
		if ((*stack)->next->index < (*stack)->next->next->index)
		{
			write(1, "ra\n", 3);
			ft_rotate(stack);
		}
		else
		{
			write(1, "sa\n", 3);
			ft_swap(stack);
			write(1, "rra\n", 4);
			ft_rev_rotate(stack);
		}
	}
	else
	{
		write(1, "sa\n", 3);
		ft_swap(stack);
	}
}

/*
** Push the two integers smallest integers from stack_a to
** stack_b, and  will grab the median of 'stack_a' between the first two limits
** of the stack 'limits' and add it to 'limits'.
*/

void	ft_insert(t_list **stack_a, t_list **stack_b, int szb)
{
	int	min;
	int	max;

	min = (*stack_a)->index;
	max = ft_lstlast(*stack_a)->index;
	while (szb)
	{
		if ((*stack_a)->index > (*stack_b)->index
			&& ft_lstlast(*stack_a)->index < (*stack_b)->index)
		{
			write(1, "pa\n", 3);
			ft_push(stack_b, stack_a);
		}
		else if (((*stack_b)->index < min || (*stack_b)->index > max)
			&& (*stack_a)->index == min)
			ft_merge(stack_a, stack_b, &min, &max);
		else
		{
			write(1, "ra\n", 3);
			ft_rotate(stack_a);
			szb++;
		}
		szb--;
	}
}

/*
** This function takes the first element at the top of 'from_stack' and puts it
** at the top of 'to_stack'.
** Or shifts down all elements of a stack by 1 - the last element
** becomes the first one.
*/

void	ft_align(t_list **stack_a, int size)
{
	t_list	*ptr;
	int		mark;

	ptr = *stack_a;
	mark = 0;
	while (ptr->index)
	{
		mark++;
		ptr = ptr->next;
	}
	ft_perform_rotation(stack_a, ptr, mark, size);
}

/*
** This function selects the type of sorting algorithm based in the size of
** 'stack_a'.
*/

void	ft_sort_small(t_list **stack_a, int size)
{
	t_list	**stack_b;
	int		red;

	if (size == 2)
		write(1, "sa\n", 3);
	else if (size == 3)
		ft_sort_3(stack_a);
	else
	{
		stack_b = malloc(sizeof(t_list *));
		if (!stack_b)
			exit(1);
		red = size;
		while (red > 3)
		{
			write(1, "pb\n", 3);
			ft_push(stack_a, stack_b);
			red--;
		}
		ft_sort_3(stack_a);
		ft_insert(stack_a, stack_b, size - red);
		ft_align(stack_a, size);
		free(stack_b);
	}
}
