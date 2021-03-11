/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:54:48 by alopes            #+#    #+#             */
/*   Updated: 2021/03/11 16:53:50 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

t_flags	ft_init_flags(void)
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

int	check_input(const char *input, va_list args)
{
	int i;
	t_flags flags;
	int count;

	i = 0;
	count = 0;
	flags = ft_init_flags();

	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int count;
	const char *input;

	input = ft_strdup((char *)format);
	count = 0;
	va_start(args, format);
	count += check_input(input, args);
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
