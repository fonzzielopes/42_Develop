# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 10:54:46 by alopes            #+#    #+#              #
#    Updated: 2021/09/13 10:44:43 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
		srcs/errors.c \
		srcs/ft_initialize_list.c \
		srcs/ft_insert_extreme.c \
		srcs/lists.c \
		srcs/moves.c \
		srcs/ordered.c \
		srcs/sort_small.c \
		srcs/free.c \
		srcs/split.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

.c.o:
	@gcc -Wall -Werror -Wextra -c $< -o  ${<:.c=.o}
all: ${NAME}

${NAME}: ${OBJS}
	@gcc -Wall -Werror -Wextra -fsanitize=address ${OBJS} -o ${NAME}

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all


.PHONY = all clean fclean re
