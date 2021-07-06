/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:12:08 by alopes            #+#    #+#             */
/*   Updated: 2021/03/31 13:13:42 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wordcount(const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			w++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		len;
	int		aindex;
	int		i;

	if (!s)
		return (NULL);
	a = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!a)
		return (0);
	a[wordcount(s, c)] = 0;
	aindex = 0;
	while (*s && *s == c)
		s++;
	len = 0;
	while (s[len])
	{
		i = len;
		while (s[len] && s[len] != c)
			len++;
		a[aindex++] = ft_substr(s, i, len - i);
		while (s[len] && s[len] == c)
			len++;
	}
	return (a);
}
