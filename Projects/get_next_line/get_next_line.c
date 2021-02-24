/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:03:35 by alopes            #+#    #+#             */
/*   Updated: 2021/02/24 17:57:06 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	size_t cnt;

	cnt = ft_strlen(*line);

	if (!(*line = malloc(BUFFER_SIZE)))
        return (-1);
	while (read(fd, buf, cnt))
	{
		return (1);
	}
	return (0);
}
