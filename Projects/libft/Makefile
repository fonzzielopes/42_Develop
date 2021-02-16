# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 21:50:33 by alopes-           #+#    #+#              #
#    Updated: 2021/02/16 14:51:45 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	 ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	 ft_isspace.c \
	 ft_memchr.c ft_memcmp.c ft_memccpy.c ft_memmove.c \
	 ft_memset.c ft_memcpy.c ft_strchr.c ft_strdup.c \
	 ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	 ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \

OBJ = $(SRCS:.c=.o)
CC = gcc
CFLAGS= -Wall -Wextra -Werror
LIB = libft.h


all: $(NAME)

.c.o: $(LIB)
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

so:
	$(CC) -c -fPIC $(CFLAGS) $(SRCS)
	gcc -shared -o libft.so $(OBJ)

re: fclean all

.PHONY: all clean fclean re
