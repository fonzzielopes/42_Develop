/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:19:58 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/03 23:55:45 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char *ptr_s1;
	char *ptr_s2;

	ptr_s1 = (char *)str1;
	ptr_s2 = (char *)str2;
	while (n > 0)
	{
		if (ptr_s1 != ptr_s2)
			return (*ptr_s1 - *ptr_s2);
		n--;
		ptr_s1++;
		ptr_s2++;
	}
	return (0);
}
