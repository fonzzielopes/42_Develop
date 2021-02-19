/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:17:31 by alopes            #+#    #+#             */
/*   Updated: 2021/02/18 15:51:03 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		if (!(ptr = (char*)malloc(1)))
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	if (ft_strlen(s) <= start + len)
		len = ft_strlen(s) - start;
	if (!(ptr = (char*)malloc(len + 1)))
		return (0);
	while (s[start] && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
