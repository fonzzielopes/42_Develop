/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_below.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:11:53 by alopes            #+#    #+#             */
/*   Updated: 2021/07/05 12:48:06 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	from_arr_closest_to_top(t_stack_overflow *stacks, int *arr, int partition)
{
	t_stack_overflow	*top;
	t_stack_overflow	*bot;

	top = last_el(stacks);
	bot = stacks;
	while (top && bot)
	{
		if (is_in(top->value, arr, partition))
			return (top->value);
		if (is_in(bot->value, arr, partition))
			return (bot->value);
		top = top->prev;
		bot = bot->next;
	}
	exit(50);
	return (INT_MIN);
}

size_t	distance_to_top(int num, t_stack_overflow *stacks)
{
	t_stack_overflow	*current;
	int		size;
	int		pos;
	size_t	distance;

	current = stacks;
	pos = 1;
	while (current)
	{
		if (current->value == num)
			break ;
		pos++;
		current = current->next;
	}
	size = (int)stack_size(stacks);
	if (size % 2 == 1 && pos > size / 2)
		distance = (size_t)ft_absolute((size / 2) - ft_absolute((size / 2) - pos
					+ 1));
	else
		distance = (size_t)ft_absolute((size / 2) - ft_absolute((size / 2) - pos));
	return (distance);
}

static t_stack_overflow	*fill(t_stack_overflow *stacks, int pile_a_b, size_t distance,
						int top_or_bot)
{
	if (top_or_bot == TOP)
		while (distance--)
			stacks = stack_command(ROTATE, pile_a_b
		, stacks);
	else if (top_or_bot == BOT)
		while (distance--)
			stacks = stack_command(REVERSE, pile_a_b, stacks);
	return (stacks);
}

t_stack_overflow	*get_num_to_top(int num, t_stack_overflow *stacks, int pile_a_b)
{
	int		top_or_bot;
	t_stack_overflow	*top;
	t_stack_overflow	*bot;
	size_t	distance;

	distance = distance_to_top(num, stacks);
	top = last_el(stacks);
	bot = stacks;
	while (1)
	{
		if (top->value == num)
		{
			top_or_bot = TOP;
			break ;
		}
		else if (bot->value == num)
		{
			top_or_bot = BOT;
			break ;
		}
		top = top->prev;
		bot = bot->next;
	}
	stacks = fill(stacks, pile_a_b, distance, top_or_bot);
	return (stacks);
}


int	get_directly_below(t_stack_overflow *stack, int num)
{
	int					directly_below;
	t_stack_overflow	*current;

	if (!stack)
		exit(1);
	directly_below = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->value > directly_below && current->value < num)
			directly_below = current->value;
		current = current->next;
	}
	if (directly_below == INT_MIN)
	{
		current = stack;
		while (current)
		{
			if (current->value > directly_below)
				directly_below = current->value;
			current = current->next;
		}
	}
	return (directly_below);
}
