/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:46:37 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/26 20:53:26 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 31)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			if (str[i] / 16 < 10)
				ft_putchar((str[i] / 16) + '0');
			if (str[i] % 16 < 10)
				ft_putchar((str[i] % 16) + '0');
			else
				ft_putchar((str[i] % 16) + 87);
		}
		i++;
	}
}
