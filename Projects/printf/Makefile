# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 12:54:58 by alopes            #+#    #+#              #
#    Updated: 2021/03/10 15:30:22 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME):    $(OBJS)
		    ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re bonus
