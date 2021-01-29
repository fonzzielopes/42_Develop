/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:41:48 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/27 23:08:52 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}
