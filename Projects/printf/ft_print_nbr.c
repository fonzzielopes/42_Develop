/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:33:42 by alopes            #+#    #+#             */
/*   Updated: 2021/03/31 12:03:07 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	get_flags(t_flags flag, int *prec, int nbr)
{
	if (((flag.dot && *prec >= 0) || flag.width < 0 || flag.minus) && flag.zero)
		flag.zero = 0;
	if (flag.zero)
	{
		*prec = flag.width;
		if (nbr < 0)
			(*prec)--;
		flag.width = 0;
	}
	return (flag);
}

int				print_nbr(int nbr, t_flags flag)
{
	char	*arr;
	int		count;
	int		prec;

	prec = flag.precision;
	flag = get_flags(flag, &prec, nbr);
	if (flag.dot && prec == 0 && nbr == 0 && flag.zero == 0)
		arr = ft_strdup("");
	else
		arr = ft_itoa_base(nbr, prec);
	if (arr == NULL)
		return (-1);
	count = print_str(arr, flag);
	free(arr);
	return (count);
}

int				print_unbr(unsigned nbr, t_flags flag)
{
	char	*arr;
	int		count;
	int		prec;

	prec = flag.precision;
	flag = get_flags(flag, &prec, 0);
	if (flag.dot && prec == 0 && nbr == 0 && flag.zero == 0)
		arr = ft_strdup("");
	else
		arr = ft_utoa_base(nbr, 10, prec);
	if (arr == NULL)
		return (-1);
	count = print_str(arr, flag);
	free(arr);
	return (count);
}

int				print_hexnbr(unsigned nbr, t_flags flag)
{
	char	*arr;
	int		count;
	int		prec;
	int		i;

	prec = flag.precision;
	flag = get_flags(flag, &prec, 0);
	if (flag.dot && prec == 0 && nbr == 0 && flag.zero == 0)
		arr = ft_strdup("");
	else
		arr = ft_utoa_base(nbr, 16, prec);
	if (arr == NULL)
		return (-1);
	i = -1;
	if (flag.type == 'X')
		while (arr[++i])
			arr[i] = ft_toupper(arr[i]);
	count = print_str(arr, flag);
	free(arr);
	return (count);
}
