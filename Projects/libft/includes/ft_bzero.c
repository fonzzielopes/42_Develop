/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:54:30 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/04 00:00:41 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void ft_bzero(void *str, size_t n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (i < n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
