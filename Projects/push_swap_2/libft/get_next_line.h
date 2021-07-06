/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:04:20 by alopes            #+#    #+#             */
/*   Updated: 2021/06/14 15:36:35 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# define BUFF_SIZE 1

int			get_next_line(int fd, char **line);

#endif
