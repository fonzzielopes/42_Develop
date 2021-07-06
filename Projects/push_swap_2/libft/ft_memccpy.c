/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:26:21 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/19 18:18:09 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	i = 0;
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (n--)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
			return ((unsigned char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
