/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:03:35 by alopes            #+#    #+#             */
/*   Updated: 2021/02/27 15:39:17 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	archive(char **saved, char **line)
{
	char	*temp;

	if (ft_strchr(*saved, '\n'))
	{
		*line = ft_substr(*saved, 0, ft_strlen(*saved)
				- ft_strlen(ft_strchr(*saved, '\n')));
		temp = *saved;
		*saved = ft_strdup(ft_strchr(temp, '\n') + 1);
		free(temp);
		return (1);
	}
	else
		return (0);
}

/*
** 1. Alocar memoria para buf
** 2. Enquanto ha texto, le e junta o saved ao buf, depois liberta (free)
** 3. Quando chega ao final do texto, copia o buf
** 4. Se chega a "\n", faz break
** Devolve o tamanho.
*/

static int	read_line(int fd, char **saved)
{
	char	*buf;
	int		size;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buf)
		return (-1);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
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

/*
** 1. Verificar situacoes de erro
** 2. Verificar primeira linha, enviar para o archivo e verificar ate encontrar "\n"
** 3. Se a linha que leu for 0, devolve EOF
** 4. Se a linha que leu tiver conteudo, volta a enviar para o archive
** 5. Se nao tiver chegado a uma "\n", copiar o conteudo para line, e libertar o saved. EOF
**
*/

int			get_next_line(int fd, char **line)
{
	static char	*saved[1024];
	int			ret;

	if (fd < 0 || line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	if (saved[fd])
		if (archive(&saved[fd], line))
			return (1);
	ret = read_line(fd, saved);
	if (ret == 0 && !saved[fd])
	{
		*line = ft_strdup(NULL);
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
