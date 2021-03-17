/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:54:48 by alopes            #+#    #+#             */
/*   Updated: 2021/03/17 16:09:59 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flags		check_format(const char **format, va_list args)
{
	t_flags flag;

	flag = ft_init_flags();
	(*format)++;
	while (!check_var(**format) && **format != '\0')
	{
		if (**format == '-') //regra para colocar à esquerda
			flag.minus = 1;
		else if (**format == '0') //preenche com zeros consoante o width
			flag.zero = 1;
		else if (**format == '*' || ft_isdigit(**format)) // especifica o num minimo de caracters a passar no output
			flag.width = get_width(&(*format), args);	//pode ser definido pela *, ou por colocar digit no format
		else if (**format == '.') // especifica maximo limite para output
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

static int			convert_flag(va_list args, t_flags flag)
{
	if (flag.type == 'c')
		return (case_char(va_arg(args, int), flag));
	if (flag.type == 's')
		return (case_str(va_arg(args, char *), flag));
	else
		return (case_char(flag.type, flag));
	return (0);
}

int					ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		temp;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		temp = count;
		if (*format == '%')
			count += convert_flag(args, check_format(&format, args));
		else
			count += case_char(*format, ft_init_flags());
		if (count < temp)
			count = -1;
		if (count < 0 || *format == '\0')
			break ;
		format++;
	}
	va_end(args);
	return (count);
}

int main (void)
{
	printf("%*.s\n", 3, "abcdef");
	ft_printf("%*.s", 3, "abcdef");

	return (0);
}
