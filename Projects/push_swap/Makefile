# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 10:54:46 by alopes            #+#    #+#              #
#    Updated: 2021/09/14 12:23:21 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	./includes/

SRCS		=	$(wildcard srcs/*.c)			\
				$(wildcard Libft/*.c)

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	gcc $(FLAGS) $< -c -o $@ -I $(INCLUDES)

all: $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
