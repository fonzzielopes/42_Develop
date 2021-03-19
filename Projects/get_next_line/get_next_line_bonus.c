/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:03:35 by alopes            #+#    #+#             */
/*   Updated: 2021/03/03 18:03:39 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				archive(char **saved, char **line)
{
	char	*temp;
	int		len;

	len = 0;
	while ((*saved)[len] != '\0' && (*saved)[len] != '\n')
		len++;
	if (ft_strchr(*saved, '\n'))
	{
		*line = ft_substr(*saved, 0, len);
		temp = *saved;
		*saved = ft_strdup(ft_strchr(temp, '\n') + 1);
		free(temp);
		return (1);
	}
	else
		return (0);
}

int				read_line(int fd, char **saved)
{
	char	*buf;
	int		size;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buf)
		return (-1);
	while ((size = read(fd, buf, BUFF_SIZE + 1)) > 0)
	{
		buf[size] = '\0';
		if (saved[fd])
		{
			temp = saved[fd];
			saved[fd] = ft_strjoin(temp, buf);
			free(temp);
		}
		else
			saved[fd] = ft_strdup(buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (size);
}

int				get_next_line(int fd, char **line)
{
	static char	*saved[1024];
	int			ret;

	if (fd < 0 || line == NULL || read(fd, 0, 0) || BUFF_SIZE <= 0)
		return (-1);
	if (saved[fd])
		if (archive(&saved[fd], line))
			return (1);
	ret = read_line(fd, saved);
	if (ret == 0 && !saved[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	if (archive(&saved[fd], line))
		return (1);
	if (!ft_strchr(saved[fd], '\n'))
	{
		*line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
		return (0);
	}
	return (0);
}
