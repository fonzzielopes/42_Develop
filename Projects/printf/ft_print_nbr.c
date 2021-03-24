/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:33:42 by alopes            #+#    #+#             */
/*   Updated: 2021/03/24 14:58:13 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags		get_flags(t_flags flag, int *prec, int nbr)
{
	if (((flag.dot && *prec >= 0) || flag.width < 0 || flag.minus) && flag.zero)
		flag.zero = 0; // todos os casos para que a flag.zero seja ignorada
	if (flag.zero)
	{ // ter atençao que flag.zero e ter padding é diferente, pois na flag é necessario contabilizar
	// a width, pois tem de continuar a ser impressa, daí termos que equilizar a nossa prec com width
		*prec = flag.width;
		if (nbr < 0)
			(*prec)--;
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
	flag = get_flags(flag, &prec, nbr);
	if (flag.dot && prec == 0 && nbr == 0 && flag.zero == 0) // todos os casos para devolver nada
		arr = ft_strdup("");
	else
		arr = ft_itoa_base(nbr, prec); // igual ao ptr, converte em str e adiciona o padding de 0's
	if (arr == NULL)
		return (-1);
	count = case_str(arr, flag);
	free(arr);
	return (count);
}
