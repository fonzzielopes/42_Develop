# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 10:36:33 by alopes-           #+#    #+#              #
#    Updated: 2021/02/04 10:40:24 by alopes-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat.c

SRCS= ft_cat.c
OBJ = $(SRCS:.c=.o)
CC = gcc
CFLAGS= -Wall -Wextra -Werror

$(NAME):
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
