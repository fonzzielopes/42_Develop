/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:09:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/22 12:42:37 by alopes           ###   ########.fr       */
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

int	check_maxmin(long num)
{
	if (num < INT_MIN)
		return (0);
	if (num > INT_MAX)
		return (0);
	return (1);
}

/*int	check_doubles(char c, char *str)
{
	if (!str)
		return (0);
	while (*str)
		if(c == *str++)
			return (1);
	return (0);
}*/


int	check_error(int argc, char **argv)
{
	int	i;
	int	j;
	int arr[1024];
	long	*nb;

	i = 1;
	arr[0] = INT_MIN;
	nb = (long *)malloc (sizeof(long));
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!check_isdigit(&argv[i][j]))
				return (0);
			j++;
		}
		arr[i] = ft_atoi(argv[i]);
		*nb = ft_atoi(argv[i]);
		if (!check_maxmin(*nb))
		{
			free(nb);
			return(0);
		}
		i++;
	/*if (!check_doubles(argv, *num))
	{
		free (num);
		return (0);
	}*/
	}
	return (1);
}
