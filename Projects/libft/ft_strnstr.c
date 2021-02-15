/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:29:43 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/08 19:08:44 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int j;

	if (!*to_find)
		return ((char*)str);
	i = 0;
	while (str[i] != '\0' && (size_t)i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] != '\0' && str[i + j] == to_find[j] &&
					(size_t)(i + j) < len)
				++j;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		++i;
	}
	return (0);
}
