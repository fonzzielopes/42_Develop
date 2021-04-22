/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:29:43 by alopes-           #+#    #+#             */
/*   Updated: 2021/04/20 14:17:20 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	int	i;
	int	j;

	if (!*to_find)
		return ((char *)s);
	i = 0;
	while (s[i] != '\0' && (size_t)i < len)
	{
		if (s[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] != '\0' && s[i + j] == to_find[j]
				&& (size_t)(i + j) < len)
				++j;
			if (to_find[j] == '\0')
				return ((char *)&s[i]);
		}
		++i;
	}
	return (0);
}
