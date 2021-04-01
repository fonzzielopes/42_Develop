/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:46:34 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/27 11:21:25 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*len;

	len = dest;
	while (*len != '\0')
		len++;
	while (*src != '\0')
	{
		*len = *src;
		len++;
		src++;
	}
	*len = '\0';
	return (dest);
}
