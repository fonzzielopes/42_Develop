# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 10:54:46 by alopes            #+#    #+#              #
#    Updated: 2021/06/08 11:41:01 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = $(wildcard srcs/*.c) \
		$(wildcard libft/*.c)

OBJ = $(SRC:.c=.o)
INC = ./includes/
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) $< c -o $@ -I $(INC)

all: $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(INC)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
