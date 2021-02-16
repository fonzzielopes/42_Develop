/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:12:12 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/16 14:34:06 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	find;

	ptr = (unsigned char *)str;
	find = (unsigned char)c;
	while (n--)
	{
		if (*ptr == find)
			return (ptr);
		ptr++;
	}
	return (NULL);
}