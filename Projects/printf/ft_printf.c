/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:54:48 by alopes            #+#    #+#             */
/*   Updated: 2021/03/26 16:57:32 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flags		check_bonus_flags(const char **format)
{
	t_flags flag;

	while (!check_var(**format) && **format != '\0')
	{
		if (**format == '#')
			flag.hash = 1;
		else if (**format == ' ')
			flag.space = 1;
		else if (**format == '+')
			flag.plus = 1 ;
		else
			break ;
		(*format)++;
	}
	(*format)--;
	return (flag);
}

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
		else if (**format == '#' || **format == ' ' || **format == '+')
			check_bonus_flags(format);
		else if (**format == '*' || ft_isdigit(**format)) // especifica o num minimo de caracters que vao sair do output
			flag.width = get_width(&(*format), args);	//pode ser definido pela *, ou por colocar digit no format
		else if (**format == '.') // especifica maximo de caracters num arg que vai sair do output
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

int					ft_printf(const char *format, ...)
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
			count += print_char(*format, ft_init_flags()); // apenas imprime char a char, nao precisa de flags(por isso sao iniciadas a 0)
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
	printf(" %#x \n", 1);
	ft_printf(" %#x ", 1);

	return (0);
}
