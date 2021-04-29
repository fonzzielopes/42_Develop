# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 12:54:58 by alopes            #+#    #+#              #
#    Updated: 2021/04/29 14:34:58 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = srcs/main.c

OBJ = $(SRC:.c=.o)

INCLUDE_DIRS = inc
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))

CC = gcc -Wall -Wextra -Werror
MLX = -lmlx -lm -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) -C ./minilibx
		@$(MAKE) -C ./libft
		$(CC) -Lminilibx -Iminilibx $(MLX) $(SRC)
		cp minilibx/libmlx.a .
		./a.out

clean:
		$(MAKE) clean -C ./libft

fclean: clean
		rm -rf $(NAME)
		$(MAKE) fclean -C ./libft
		rm -rf libmlx.a
		rm -rf srcs/main.o
		rm -rf ./a.out

re: fclean all

.PHONY: all clean fclean re
