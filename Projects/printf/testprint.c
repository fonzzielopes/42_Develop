/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:44:56 by alopes            #+#    #+#             */
/*   Updated: 2021/03/11 16:45:20 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

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
