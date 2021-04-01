/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:56:56 by alopes            #+#    #+#             */
/*   Updated: 2021/01/13 16:00:31 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (str[0] != '\0')
	{
		ft_putchar(str[0]);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
