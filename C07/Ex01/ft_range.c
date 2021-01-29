/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:43:31 by alopes-           #+#    #+#             */
/*   Updated: 2021/01/29 20:41:06 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *array;
	int size;
	int i;

	size = max - min;
	i = 0;
	if (min >= max)
		return (0);
	array = (int *)malloc(size * sizeof(int));
	while (min < max)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
