/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:56:55 by alopes            #+#    #+#             */
/*   Updated: 2021/03/11 14:24:46 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct		s_flags
{
	int				dot;
	int 			star;
	int				minus;
	int				zero;
	int				width;
	int				type;
	int				min_width;
	int				sign;

}					t_flags;

int					ft_printf(const char *format, ...);

#endif
