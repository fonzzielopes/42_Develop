# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alopes <alopes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 12:54:58 by alopes            #+#    #+#              #
#    Updated: 2021/04/22 13:01:27 by alopes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = srcs/main.c

OBJ = $(SRC:.c=.o)

INCLUDE_DIRS = inc
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -lm -framework OpenGL -framework Appkit

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ)
		@$(MAKE) -C ./minilibx
		@$(MAKE) -C ./libft
		$(CC) $(CFLAGS) -Lminilibx $(MLX) -Llibft -lft -Ilibft -Iminilibx
		cp ./minilibx/libmlx.a .

clean:
		$(MAKE) clean -C ./libft

fclean: clean
		rm -rf $(NAME)
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./minilibx
		rm -rf libmlx.a

re: fclean all

.PHONY: all clean fclean re
