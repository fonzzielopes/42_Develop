/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:13:44 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/18 17:17:17 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;
	int		operation;
	int		begin;

	begin = 0;
	pdst = (char *)dst;
	psrc = (char *)src;
	if (n == 0 || dst == src)
		return (dst);
	if (src > dst)
		operation = 1;
	else
	{
		begin = n - 1;
		operation = -1;
	}
	while (n--)
	{
		*(pdst + begin) = *(psrc + begin);
		begin += operation;
	}
	return (dst);
}
