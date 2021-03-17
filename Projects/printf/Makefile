# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 12:54:58 by alopes            #+#    #+#              #
#    Updated: 2021/03/17 11:08:48 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c ft_print_cases.c
OBJ = $(SRC:.c=.o)
INCLUDEDIR = ./
HEADERS = $(INCLUDEDIR)ft_printf.h
LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -c

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)
	cp $(LIBFT) ./$(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@/bin/rm -f $(NAME)

re: fclean all
