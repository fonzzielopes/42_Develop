/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:58:44 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/27 13:08:24 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	s1;
	unsigned int	s2;
	unsigned int	i;

	i = 0;
	s1 = 0;
	s2 = 0;
	if (size == 0)
		return (s1);
	s1 = ft_strlen(src);
	s2 = ft_strlen(dest);
	if (size <= s2)
		return (size + s1);
	i = 0;
	while (size && (size - 1 - s2) && src[i])
	{
		dest[s2 + i] = src[i];
		i++;
		size--;
	}
	dest[s2 + i] = '\0';
	return (s1 + s2);
}
