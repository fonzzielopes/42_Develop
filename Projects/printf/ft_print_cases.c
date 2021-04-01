/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:12:27 by alopes            #+#    #+#             */
/*   Updated: 2021/03/29 15:57:26 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_printspaces(t_flags flag, int len)
{
	int		count;

	count = 0;
	if (flag.width < 0)
		flag.width = -flag.width;
	while (flag.width-- > len)
	{
		if (flag.zero == 1 && flag.minus == 0)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	return (count);
}

static t_flags	width_spec(t_flags flag, int *len)
{
	if (flag.precision < 0)
		flag.dot = 0;
	if (flag.width < 0) // regra do width negativa para a esquerda, primeiro vez que é definido
		flag.minus = 1;
	if (flag.dot && *len > flag.precision && flag.type == 's')
	/* tem que ter '.', comprimento da str nao pode ser menor que a precision para depois ser definida como arg principal
	tem de ser tambem uma string, pois apos definiçao de precision ele vai ignorar os args passados */
		*len = flag.precision; // definimos o valor max a ser impresso como len
	return (flag);
}

int				print_char(char c, t_flags flag)
{
	int		count;

	count = 0;
	if (flag.minus == 1 || flag.width < 0)
	// Passa para a esquerda, importante a regra caso passem uma width negativa
	{
		count += write(1, &c, 1);
		count += ft_printspaces(flag, 1);
	}
	else
	{
		count += ft_printspaces(flag, 1);
		count += write(1, &c, 1);
	}
	return (count);
}

int				print_str(char *str, t_flags flag)
{
	int		count;
	int 	len;

	count = 0;
	if (str == NULL)
		return (print_str("(null)", flag)); // String becomes string literal “(null)”
	len = ft_strlen(str);
	flag = width_spec(flag, &len); // vamos ler a width que foi definida como arg
	if (flag.minus == 1) // começa impressao da esquerda
	{
		count += write(1, str, len); //mandar imprimir str, com a len correspondente
		count += ft_printspaces(flag, len); // mesmas regras qe o case_char
	}
	if (flag.minus == 0)
	{
		count += ft_printspaces(flag, len);
		count += write(1, str, len);
	}
	return (count);
}

int				print_ptr(unsigned long *ptr, t_flags flag)
{
	char	*arr;
	int		count;
	int		prec;

	count = 0;
	prec = flag.precision; //precisamos de saber a prec para verificar o padding de 0's necessario
	arr = ft_itoa_hex(ptr, prec); // feito nesta conversao do ptr para str
	if (arr == NULL)
		return (-1);
	count += print_str(arr, flag);
	free(arr); // proteger de leaks
	return (count);
}
