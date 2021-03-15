/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:54:48 by alopes            #+#    #+#             */
/*   Updated: 2021/03/15 16:32:56 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_flags	ft_init_flags(void)
{
	t_flags flag;
	flag.dot = 0;
	flag.star = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.type = 0;

	return(flag);
}

int	check_var(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static t_flags check_format(const char **format)
{
	t_flags flag;

	flag = ft_init_flags();
	(*format)++; //para dar o caracter a seguir a %
	while (!check_var(**format) && **format != '\0')
	{
		if (**format == '-')
			flag.minus = 1;
		else if (**format == '0')
			flag.zero = 1;
		else if (**format == '*')//width tem que ter mais regras
			flag.width = 1;
		else if (**format == '.')//precision tem que ter mais regras
			flag.dot = 1;
		else
			break ;
		(*format)++;
	}
	flag.type = **format;
	return (flag);
}

 int	convert_flag(va_list args, t_flags flag)
{
	if (flag.type == 'c')
		return (case_char(va_arg(args, int), flag));
	else
		return (case_char(flag.type, flag));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	int temp;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (format)
	{
		temp = count;
		if (*format == '%')
			count += convert_flag(args, check_format(&format));
		else
			count += case_char(*format, ft_init_flags());
		if (count < temp) //situaçao de erro
			count = -1;
		if (count < 0 || *format == '\0')
			break ;
		format++;
	}
	va_end(args);
	return (count);
}
/*
int main (void)
{
	printf("%c\n", '0');
	ft_printf("%c\n", '0');

	return (0);
}*/
