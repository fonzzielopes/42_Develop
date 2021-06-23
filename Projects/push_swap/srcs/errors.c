/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:09:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/23 12:34:26 by alopes           ###   ########.fr       */
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

int	check_dup(char *str[])
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;
	int arr[1024];
	//long	*nb;
	//int temp;

	i = 1;
	arr[0] = INT_MIN;
	//nb = (long *)malloc (sizeof(long));
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		j = 0;
		/*temp = ft_atoi(argv);
		if ((!temp) || (temp > 2147483647) || (temp < -2147483648))
            return (0);
		if (!check_maxmin(temp))
			return (0);*/
		while (argv[i][j])
		{
			if (!check_isdigit(&argv[i][j]) || !check_dup(*argv[i]))
				return (0);
			j++;
		}
		arr[i] = ft_atoi(argv[i]);
		//*nb = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}
