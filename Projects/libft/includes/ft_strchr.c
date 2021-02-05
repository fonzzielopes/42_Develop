/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:42:47 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/04 22:58:36 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *src)
{
	int size;

	size = 0;
	while (src[size])
	{
		size++;
	}
	return (size);
}

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	char	*rem;
	int		i;

	ptr = (char*)str;
	i = 0;
	while (i < ft_strlen((char *)str))
	{
		if (ptr[i] != c)
			i++;
		else
		{
			rem = ptr + i;
			break ;
		}
	}
	return (rem);
}
