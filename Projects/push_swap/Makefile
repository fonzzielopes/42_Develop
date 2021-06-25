# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 10:54:46 by alopes            #+#    #+#              #
#    Updated: 2021/06/25 10:35:12 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = srcs/errors.c \
		srcs/collect_create.c \
		srcs/lets_sort.c \
		srcs/push_swap.c

##OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
INC = -Iincludes -Llibft -lft
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	gcc $(FLAGS) $(INC) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY = all clean fclean re
