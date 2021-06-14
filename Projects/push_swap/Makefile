# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 10:54:46 by alopes            #+#    #+#              #
#    Updated: 2021/06/14 16:32:42 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = $(wildcard srcs/*.c) \
		$(wildcard libft/*.c)

OBJ = $(SRC:.c=.o)
INCLUDEDIR = ./
HEADERS = $(INCLUDEDIR)push_swap.h
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) $< -c -o $@ -I $(HEADERS)

all: $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
