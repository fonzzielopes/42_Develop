/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:04:20 by alopes            #+#    #+#             */
/*   Updated: 2021/02/24 18:06:45 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#	include <string.h>
#	include <stdlib.h>
#	include <unistd.h>

# define BUFFER_SIZE 32

char		*ft_strchr(const char *str, int c);
char		*ft_strdup(char *src);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
