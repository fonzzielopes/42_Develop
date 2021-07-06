/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:24:16 by alopes-           #+#    #+#             */
/*   Updated: 2021/06/30 17:00:12 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (0);
	while ((s1[count] == s2[count] && s1[count] && s2[count]) && n > count + 1)
		count++;
	return (((unsigned char *)s1)[count] - ((unsigned char *)s2)[count]);
}
