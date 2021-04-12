/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:54:48 by alopes            #+#    #+#             */
/*   Updated: 2021/03/31 12:02:57 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flags	check_format(const char **format, va_list args)
{
	t_flags	flag;

	flag = ft_init_flags();
	(*format)++;
	while (!check_var(**format) && **format != '\0')
	{
		if (**format == '-')
			flag.minus = 1;
		else if (**format == '0')
			flag.zero = 1;
		else if (**format == '*' || ft_isdigit(**format))
			flag.width = get_width(&(*format), args);
		else if (**format == '.')
		{
			flag.dot = 1;
			flag.precision = get_precision(&(*format), args);
		}
		else
			break ;
		(*format)++;
	}
	flag.type = **format;
	return (flag);
}

static int		convert_flag(va_list args, t_flags flag)
{
	if (flag.type == 'c')
		return (print_char(va_arg(args, int), flag));
	if (flag.type == 's')
		return (print_str(va_arg(args, char *), flag));
	if (flag.type == 'p')
		return (print_ptr(va_arg(args, unsigned long *), flag));
	if (flag.type == 'd' || flag.type == 'i')
		return (print_nbr(va_arg(args, int), flag));
	if (flag.type == 'u')
		return (print_unbr(va_arg(args, unsigned), flag));
	if (flag.type == 'x' || flag.type == 'X')
		return (print_hexnbr(va_arg(args, unsigned), flag));
	else
		return (print_char(flag.type, flag));
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		temp;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		temp = count;
		if (*format == '%')
			count += convert_flag(args, check_format(&format, args));
		else
			count += print_char(*format, ft_init_flags());
		if (count < temp)
			count = -1;
		if (count < 0 || *format == '\0')
			break ;
		format++;
	}
	va_end(args);
	return (count);
}
