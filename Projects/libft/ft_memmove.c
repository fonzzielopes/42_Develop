/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:13:44 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/10 15:04:50 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;
	size_t	i;
	int		operation;
	int		begin;

	begin = 0;
	ptr_d = (char *)dest;
	ptr_s = (char *)src;
	i = 0;
	if (src > dest)
		operation = 1;
	else
	{
		begin = n - 1;
		operation = -1;
	}
	while (i < n)
	{
		*(ptr_d + begin) = *(ptr_s + begin);
		begin += operation;
		i++;
	}
	return (dest);
}
