/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:29:33 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/28 17:36:41 by alopes-          ###   ########.fr       */
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

	i = 1;
	if (ac > 0)
	{
		while (i < ac)
		{
			ft_putstr(ag[i]);
			i++;
			write(1, "\n", 1);
		}
	}
}
