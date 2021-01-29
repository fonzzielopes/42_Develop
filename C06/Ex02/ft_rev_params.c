/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:37:51 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/28 17:43:47 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int ac, char **ag)
{
	int i;

	i = 0;
	if (ac > 0)
	{
		while (i < ac - 1)
		{
			ft_putstr(ag[ac - 1 - i]);
			i++;
			write(1, "\n", 1);
		}
	}
}
