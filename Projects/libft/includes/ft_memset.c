/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:12:30 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/02 23:54:00 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = str;
	while (i < n)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (str);
}
