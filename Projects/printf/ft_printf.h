/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:56:55 by alopes            #+#    #+#             */
/*   Updated: 2021/03/23 12:14:51 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int				dot;
	int				precision;
	int				minus;
	int				zero;
	int				width;
	int				type;

}					t_flags;

int					ft_printf(const char *format, ...);
int					check_var(char c);
t_flags				ft_init_flags(void);
int					case_char(char c, t_flags flag);
int					case_str(char *str, t_flags flag);
int					case_ptr(unsigned long *ptr, t_flags flag);
int					case_nbr(int nbr, t_flags flag);
int					get_width(const char **format, va_list args);
int					get_precision(const char **format, va_list args);


#endif
