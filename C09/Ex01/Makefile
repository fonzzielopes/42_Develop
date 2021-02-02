# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 12:43:06 by alopes-           #+#    #+#              #
#    Updated: 2021/02/02 01:17:39 by alopes-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJ = $(SRCS:.c=.o)
INC = includes
CC = gcc
CFLAGS= -Wall -Wextra -Werror


.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I$(INC)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
