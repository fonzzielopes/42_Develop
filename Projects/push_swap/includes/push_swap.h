/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:43:17 by alopes            #+#    #+#             */
/*   Updated: 2021/06/14 15:17:55 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_data
{
	int				value;
	struct s_data	*next;
	struct s_data	*prev;

}				t_data;

typedef struct s_stack_overflow
{
	t_data			*stack_a;
	t_data			*stack_b;
	long			length;
}				t_stack_overflow;

long					*check_error(char **argv);
t_stack_overflow		*init_stacks(void);

#endif
