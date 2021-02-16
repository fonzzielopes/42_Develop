/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:27:08 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/16 17:22:37 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (char)c)
			ptr = (char *)str;
		++str;
	}
	if (ptr)
		return (ptr);
	if (c == '\0')
		return ((char *)str);
	return (0);
}
