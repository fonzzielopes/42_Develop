/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:24:06 by alopes            #+#    #+#             */
/*   Updated: 2021/03/31 12:03:02 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flag;

	flag.precision = 0;
	flag.dot = 0;
	flag.width = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.type = 0;
	flag.hash = 0;
	flag.space = 0;
	flag.plus = 0;
	return (flag);
}

int		check_var(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		get_width(const char **format, va_list args)
{
	int	width;

	width = 0;
	if (**format == '*')
		width = va_arg(args, int);
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
	return (width);
}

int		get_precision(const char **format, va_list args)
{
	int		precision;

	precision = 0;
	if (*(*format + 1) == '*')
	{
		(*format)++;
		precision = va_arg(args, int);
	}
	if (ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		precision = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	return (precision);
}
