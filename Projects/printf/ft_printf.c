/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:54:48 by alopes            #+#    #+#             */
/*   Updated: 2021/03/11 16:17:47 by alopes           ###   ########.fr       */
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
	char *input;
	char *temp;

	input = ft_strdup((char *)format);
	count = 0;
	va_start(args, format);
	while(input && input[count])
	{
		if (input[count] != '%')
			ft_putchar(input[count]);
		else
		{
			count++;
			if (input[count] == 's')
			{
				temp = va_arg(args, char *);
				ft_putstr(temp);
			}
		}
		count++;
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
