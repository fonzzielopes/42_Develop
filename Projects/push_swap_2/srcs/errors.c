/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:09:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/29 17:38:40 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isdigit (char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str [i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_isdup(char *str[])
{
	int		i;
	int		j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	int		i;
	int		j;
	long	temp;

	i = 1;
	if (argc == 1)
		return (0);
	if (check_isdup(argv))
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!check_isdigit(&argv[i][j]))
				return (0);
			j++;
		}
		temp = ft_atol(argv[i]);
		if (ft_strlen(argv[i]) > 11
			|| temp > 2147483647 || temp < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
