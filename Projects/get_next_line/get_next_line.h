/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:04:20 by alopes            #+#    #+#             */
/*   Updated: 2021/02/27 12:52:03 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#	include <string.h>
#	include <stdlib.h>
#	include <fcntl.h>
#	include <sys/types.h>
#	include <unistd.h>
#	include <stdio.h>
# ifndef BUFF_SIZE
#  define BUFF_SIZE 8
# endif

typedef struct		s_list
{
	void			*content;
	size_t			*content_size;
	struct s_list	*next;
}					t_list;


int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(char *src);
size_t		ft_strlen(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
