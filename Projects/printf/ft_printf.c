/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:54:48 by alopes            #+#    #+#             */
/*   Updated: 2021/03/11 15:52:19 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"
/*
t_flags	ft_flags(void)
{
	t_flags flags;
	flags.dot = 0;
	flags.star = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.type = 0;
	flags.min_width = 0;

	return(flags);
}
*/
int ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;
	char *input;
	char *temp;

	i = 0;
	input = ft_strdup((char *)format);
	count = 0;
	va_start(args, format);
	while(input && input[i])
	{
		if (input[i] != '%')
			ft_putchar(input[i]);
		else
		{
			i++;
			if (input[i] == 's')
			{
				temp = va_arg(args, char *);
				ft_putstr(temp);
			}
		}
		i++;
	}
	va_end(args);
	free((char *)input);
	return (count);
}

int main (void)
{
	printf("Hello %s! You are %s!\n", "Afonso", "cool");
	ft_printf("Hello %s! You are %s!\n", "Afonso", "cool");

	return (0);
}
