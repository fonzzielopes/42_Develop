/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:03:35 by alopes            #+#    #+#             */
/*   Updated: 2021/03/03 12:18:02 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** 1. Verificar o tamanho de saved
** 2. Enquanto le ate "\n", aloca memoria e devolve em line a linha exacta de saved
** 3. Guarda saved no temp
** 4. Copia e aloca novamente para saved espaço para o temp ate "\n" e NULL
** 5. Liberta o temp
** 6. Devolve 1 para continuar
** 7. Ou devolve zero para EOF
*/

static int	archive(char **saved, char **line)
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

/*
** Ler linhas e devolver o seu tamanho para o archivo
** 1. Alocar memoria para buf
** 2. Se buf for NULL, devolve erro
** 3. Enquanto size for maior de 0 (porque ha texto para ler e nao chegou a EOF:
** Se houver algo para ler em saved
** 	3.1 Guarda saved no temp;
**	3.2 Saved passa a ser o total de temp lido byte a byte lido com o buf;
**	3.3 Liberta o temp;
** Caso nao haja
** 3.4 Copia e aloca o que existe em buf para saved
** Se chega econtrar uma "\n", termina o processo com break
** 4. Liberta buf
*/

int			read_line(int fd, char **saved)
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
** 2. Verificar primeira linha, enviar para o archivo
** e verificar ate encontrar "\n"
** 3. Se a seguinte linha que ler for 0, copia nada e devolve EOF
** 4. Se a linha que leu tiver conteudo verificado no archive for verdadeiro,
** continua a ler
** 5. Ate nao tiver chegado a uma "\n", copiar o conteudo para line,
** e libertar o saved. EOF
**
*/

int			get_next_line(int fd, char **line)
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
