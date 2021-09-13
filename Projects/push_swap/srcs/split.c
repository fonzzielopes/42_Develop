/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:12:56 by alopes            #+#    #+#             */
/*   Updated: 2021/09/13 10:51:37 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nword(char const *s, char c)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (s[i - 1])
	{
		if (s[i - 1] != c && (s[i] == '\0' || s[i] == c))
			n++;
		i++;
	}
	return (n);
}

static int	ft_wrdlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_splitwrd(char **tab, char *s2, char const *s, char c)
{
	int	i;
	int	j;
	int	wlen;

	i = 0;
	j = 0;
	while (s2[j] && i < ft_nword(s, c))
	{
		if (s2[j] != c)
		{
			tab[i] = malloc(sizeof (char) * (ft_wrdlen(&s2[j], c) + 1));
			wlen = 0;
			while (s2[j] && s2[j] != c)
			{
				tab[i][wlen] = s2[j];
				wlen++;
				j++;
			}
			tab[i][wlen] = '\0';
			i++;
		}
		else
			j++;
	}
	tab[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*s2;

	s2 = (char *)s;
	tab = malloc(sizeof (char *) * (ft_nword(s, c) + 1));
	if (!tab)
		return (0);
	ft_splitwrd(tab, s2, s, c);
	return (tab);
}
