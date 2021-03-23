/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:33:42 by alopes            #+#    #+#             */
/*   Updated: 2021/03/23 15:16:39 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags		get_flags(t_flags flag, int *prec)
{
	if ((flag.dot || flag.width < 0 || flag.minus) && flag.zero)
		flag.zero = 0;
	if (flag.zero)
	{
		*prec = flag.width;
		flag.width = 0;
	}
	return (flag);
}


int				case_nbr(int nbr, t_flags flag)
{
	char	*arr;
	int		count;
	int		prec;

	prec = flag.precision;
	flag = get_flags(flag, &prec);
	arr = ft_itoa_base(nbr, prec); //adiciona o padding de 0s
	if (arr == NULL)
		return (-1);
	count = case_str(arr, flag);
	free(arr);
	return (count);
}
