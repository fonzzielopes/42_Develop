/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:02:22 by alopes            #+#    #+#             */
/*   Updated: 2021/06/28 18:11:16 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define STACK_A 0
# define STACK_B 1


typedef struct s_stack_overflow
{
	int						value;
	struct s_stack_overflow	*next;
	struct s_stack_overflow	*prev;
}				t_stack_overflow;

int						check_error(int argc, char *argv[]);
t_stack_overflow		*create_list(int argc, char **argv);
t_stack_overflow 		*sort(t_stack_overflow *stacks, int stack_a);
size_t					stack_size(t_stack_overflow *stacks);
int						check_sorted(t_stack_overflow *stacks);
t_stack_overflow		*first_el(t_stack_overflow *stacks);
t_stack_overflow		*last_el(t_stack_overflow *stacks);
t_stack_overflow		*sort_2(t_stack_overflow *stack, int pile_a_b);
t_stack_overflow		*stack_command(t_stack_overflow *stacks, int pile_a_b);
#endif
