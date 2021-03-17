/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:12:27 by alopes            #+#    #+#             */
/*   Updated: 2021/03/17 16:10:03 by alopes           ###   ########.fr       */
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
/*
static t_flags	ft_definewidth(t_flags flag, int *len)
{
	if (flag.precision < 0)
		flag.dot = 0;
	if (flag.width < 0)
		flag.minus = 1;
	if (flag.dot && *len > flag.precision && flag.type == 's')
		*len = flag.precision;
	return (flag);
}
*/
int				case_char(char c, t_flags flag)
{
	int		count;

	count = 0;
	if (flag.minus == 1 || flag.width < 0)
	/* Passa para a esquerda, importante a regra caso passem uma width negativa */
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

int				case_str(char *str, t_flags flag)
{
	int		count;
	int 	len;

	count = 0;
	if (str == NULL)
		return (case_str("(null)", flag));
	len = ft_strlen(str);
	//flag = ft_definewidth(flag, &len);
	if (flag.minus == 1)
	{
		count += write(1, str, len);
		count += ft_printspaces(flag, len);
	}
	if (flag.minus == 0)
	{
		count += ft_printspaces(flag, len);
		count += write(1, str, len);
	}
	return (count);
}
