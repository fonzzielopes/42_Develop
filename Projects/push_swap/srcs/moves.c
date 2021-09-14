/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:32:18 by alopes            #+#    #+#             */
/*   Updated: 2021/09/13 12:10:13 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Exchanges first and second elements in the stack
void	ft_swap(t_list **stack)
{
	t_list	*temp;

	if (!(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp -> next = *stack;
	*stack = temp;
}

// Upshifts elements one place (first -> last)
void	ft_rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack)->next)
		return ;
	temp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

// Downshifts elements one place (last -> first)
void	ft_rev_rotate(t_list **stack)
{
	t_list	*ptr;
	t_list	*last;

	if (!(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	ptr = *stack;
	*stack = last;
	while (ptr->next != last)
		ptr = ptr->next;
	ptr->next = NULL;
}

//Moves first element of origin to first place in dest.
void	ft_push(t_list **start, t_list **dest)
{
	t_list	*temp;

	temp = *start;
	*start = (*start)->next;
	ft_lstadd_front(dest, temp);
}

/*Decides wether it is better to rotate or to rev rotate and performs
the operation.*/
void	ft_perform_rotation(t_list **stack_a, t_list *ptr, int mark, int size)
{
	if (mark <= size / 2)
	{
		while (*stack_a != ptr)
		{
			write(1, "ra\n", 3);
			ft_rotate(stack_a);
		}
	}
	else
	{
		while (*stack_a != ptr)
		{
			write(1, "rra\n", 4);
			ft_rev_rotate(stack_a);
		}
	}
}
