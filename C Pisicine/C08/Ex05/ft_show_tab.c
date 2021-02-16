/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:47:08 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/05 14:19:16 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int size)
{
	if (size > 9)
		ft_putnbr(size / 10);
	write(1, &"0123456789"[size % 10], 1);
}

void	ft_show_tab(struct s_stock_str *obj)
{
	int	i;

	i = 0;
	while (obj[i].str != NULL)
	{
		ft_putstr(obj[i].str);
		ft_putstr("\n");
		ft_putnbr(obj[i].size);
		ft_putstr("\n");
		ft_putstr(obj[i].copy);
		ft_putstr("\n");
		i++;
	}
}
