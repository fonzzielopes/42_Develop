/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:54:05 by alopes            #+#    #+#             */
/*   Updated: 2021/06/24 11:59:32 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	result;
	long	index;
	long	sign;

	if (str == NULL)
		return (0);
	result = 0;
	index = 0;
	sign = 1;
	while (str[index] == ' ')
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	while (str[index] != '\0' && (str[index] >= '0' && str[index] <= '9'))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * sign);
}
