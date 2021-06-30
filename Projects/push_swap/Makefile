# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 10:54:46 by alopes            #+#    #+#              #
#    Updated: 2021/06/30 17:16:50 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
		srcs/errors.c \
		srcs/lets_sort.c \
		srcs/collect_create.c \
		srcs/push.c \
		srcs/swap.c \
		srcs/rotate.c \
		srcs/rev_rotate.c \
		srcs/sort_2.c \
		srcs/sort_3.c \
		srcs/stack_op.c

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
INC = -Iincludes -Llibft -lft
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	gcc $(FLAGS) $(INC) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY = all clean fclean re
