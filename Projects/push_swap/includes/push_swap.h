/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:43:17 by alopes            #+#    #+#             */
/*   Updated: 2021/06/09 12:36:51 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_stack_overflow
{
	int						value;
	struct s_stack_overflow	*next;
	struct s_stack_overflow	*prev;

}				t_stack_overflow;

int		*check_error(char *argv, t_stack_overflow);

#endif
