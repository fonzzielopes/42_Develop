/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:25:59 by alopes            #+#    #+#             */
/*   Updated: 2021/06/28 18:18:21 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	index;

	index = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}
