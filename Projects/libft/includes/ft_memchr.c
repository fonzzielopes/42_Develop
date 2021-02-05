/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:12:12 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/03 23:13:11 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*ptr;
	char	*find;

	ptr = (char *)str;
	find = 0;
	while ((str != 0) && (n--))
	{
		if (*ptr != c)
			ptr++;
		else
		{
			find = ptr;
			break ;
		}
	}
	return (find);
}
