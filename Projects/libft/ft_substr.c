/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:47:35 by alopes            #+#    #+#             */
/*   Updated: 2021/02/23 12:57:05 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	if (size < len)
		len = size;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr || !s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
		while (s[start + i] && i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
	ptr[i] = '\0';
	return (ptr);
}
