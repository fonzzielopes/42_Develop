/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:15:37 by alopes            #+#    #+#             */
/*   Updated: 2021/09/13 10:47:46 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Frees the split if it was applied during parsing
void	ft_free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

// Frees stack a after ordering everything
void	ft_free_stack(t_list **stack)
{
	t_list	*ptr;

	while (*stack)
	{
		ptr = (*stack)->next;
		free((*stack)->binary);
		free(*stack);
		*stack = ptr;
	}
}

// Frees the int arrays in case of error
void	ft_free_array(int *args, int *order)
{
	free(args);
	free(order);
}
