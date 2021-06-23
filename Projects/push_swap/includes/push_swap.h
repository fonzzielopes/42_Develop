/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:02:22 by alopes            #+#    #+#             */
/*   Updated: 2021/06/23 11:21:48 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack_overflow
{
	int						value;
	struct s_stack_overflow	*next;
	struct s_stack_overflow	*prev;
}				t_stack_overflow;

int						check_error(int argc, char *argv[]);
t_stack_overflow		*create_list(int argc, char **argv);

#endif
