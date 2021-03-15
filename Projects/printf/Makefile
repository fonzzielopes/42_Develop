# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 12:54:58 by alopes            #+#    #+#              #
#    Updated: 2021/03/15 16:22:26 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c print_cases.c
OBJS = $(SRCS:.c=.o)
INCLUDEDIR = ./
HEADERS = $(INCLUDEDIR)ft_printf.h
LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -c

all: $(NAME)

$(NAME):    $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)
	cp $(LIBFT) ./$(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@/bin/rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus
