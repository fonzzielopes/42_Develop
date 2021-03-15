/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:56:55 by alopes            #+#    #+#             */
/*   Updated: 2021/03/15 15:29:57 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct		s_flags
{
	int				dot;
	int 			star;
	int				minus;
	int				zero;
	int				width;
	int				type;

}					t_flags;

int					ft_printf(const char *format, ...);
int					check_var(char c);
t_flags				ft_init_flags(void);
int					case_char(char c, t_flags flag);



#endif
