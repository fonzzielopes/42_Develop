/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:04:43 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/27 12:31:53 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*len;

	len = dest;
	while (*len != '\0')
	{
		len++;
	}
	i = 0;
	while (*src != '\0' && i < nb)
	{
		*len = *src;
		len++;
		src++;
		i++;
	}
	*len = '\0';
	return (dest);
}
