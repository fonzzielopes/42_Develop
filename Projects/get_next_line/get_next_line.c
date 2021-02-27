/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:03:35 by alopes            #+#    #+#             */
/*   Updated: 2021/02/27 14:06:08 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static int archive (char **saved, *line);

static int	result(char **saved, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && saved[fd] == NULL)
		return (0);
	else
		return (archive(&saved[fd], line));
}

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *saved[1024];
	char *tmp;
	int ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
        if (saved[fd] == NULL)
            saved[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(saved[fd], buf);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (ft_strchr(saved[fd], '\n'))
			break ;
	}
	return (result(saved, line, ret, fd));
}*/

/*
** Con esta funcion buscamos las lineas y las guardamos una a una.
** 1. Chequeamos el stack buscando la primera linea.
** 2. Hacemos un substr guardando la linea.
** 3. Hacemos copia de stack en temp y duplicamos la linea con strdup en stack.
** 4. Liberamos temp y devolvemos 1 si ha ido bien.
*/

static int	archive(char **saved, char **line)
{
	char	*temp;

	if (ft_strchr(*saved, '\n'))
	{
		*line = ft_substr(*saved, 0, ft_strlen(*saved) -
				ft_strlen(ft_strchr(*saved, '\n')));
		temp = *saved;
		*saved = ft_strdup(ft_strchr(temp, '\n') + 1);
		free(temp);
		return (1);
	}
	else
		return (0);
}

/*
** Esta funcion lee las lineas del archivo
** 1. Alocamos memoria para buf
** 2. Mientras que haya texto, lee y une el stack con el buf. Luego libera.
** 3. Si llega al final del texto hace un strdup de buf.
** 4. Si llega al final de linea, rompe el bucle.
** Devuelve el numero de bytes leidos.
*/

static int	read_line(int fd, char **saved)
{
	char	*buf;
	int		bytes;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buf)
		return (-1);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
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
	return (bytes);
}

int			get_next_line(int fd, char **line)
{
	static char	*saved[1024];
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, saved, 0) < 0)
		return (-1);
	if (saved[fd])
		if (archive(&saved[fd], line))
			return (1);
	ret = read_line(fd, saved);
	buf[ret] = '\0';
	if (ret == 0 && !saved[fd])
	{
		*line = ft_strdup(buf);
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
/*
int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("bart_top.txt", O_RDWR);
	if (ac == 1)
		fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%d", get_next_line(fd, &line));
		printf("%s\n", line);
		free(line);
	}
	printf("%d", get_next_line(fd, &line));
	printf("%s",line);
	free(line);
	//while (1)
	//{

	//}
	close(fd);
	return (0);
}
*/
