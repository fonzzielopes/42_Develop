/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:26:21 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/03 23:13:36 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;
	char	*ptr;
	int		i;

	ptr_d = (char *)dest;
	ptr_s = (char *)src;
	ptr = 0;
	i = 0;
	while (i < n && ptr == 0)
	{
		ptr_d[i] = ptr_s[i];
		if (ptr_s[i] == c)
			ptr = dest;
			i++;
	}
	return (ptr);
}

int main(void)
{
	char *msg = "This is the string not copied";
	char buffer[80];
	memset( buffer, '\0', 80 );
	ft_memccpy( buffer, msg, ':', 80 );
	printf( "%s\n", buffer );
}


