/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:58:29 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/10 20:55:28 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t n, size_t size)
{
	unsigned	i;
	unsigned	nb;
	char		*ptr;

	i = 0;
	nb = n * size;
	ptr = malloc(sizeof(nb) + 1);
	while (i < nb)
	{
		*ptr++ = 0;
		i++;
	}
	return (ptr);
}
