/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:12:27 by alopes            #+#    #+#             */
/*   Updated: 2021/03/15 16:33:56 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_printspaces(t_flags flag, int len)
{
	int		rtval;

	rtval = 0;
	if (flag.width < 0)
		flag.width = -flag.width;
	while (flag.width-- > len)
	{
		if (flag.zero == 1 && flag.minus == 0)
			rtval += write(1, "0", 1);
		else
			rtval += write(1, " ", 1);
	}
	return (rtval);
}

int				case_char(char c, t_flags flag)
{
	int		count;

	count = 0;
	if (flag.minus == 1 || flag.width < -1)// para colocar à esquerda
	{
		count += write(1, &c, 1);
		count += ft_printspaces(flag, 1);
	}
	else
		count += ft_printspaces(flag, 1);
		count += write(1, &c, 1);
	return (count);
}
