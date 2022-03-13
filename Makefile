# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 16:19:10 by bade-lee          #+#    #+#              #
#    Updated: 2022/03/13 15:04:12 by bade-lee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror -Imlx
INCLUDE = -I src/so_long.h
LIB = libft/libft.a
MLX = minilibx/libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit

#          ----------========== {     SRCS     } ==========----------

SRC = src/main.c

#          ----------========== {     OBJS     } ==========----------

OBJ = $(SRC:.c=.o)

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -sC minilibx
	@$(CC) $(FLAGS) $(MLXFLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)
	@printf "\e[1;32m.\e[0;m"

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@printf "\e[0;31m[.o files deleted]\e[0;m"

fclean: clean
	@make -C libft fclean
	@make -C minilibx clean
	@rm -f $(NAME)
	@printf "\e[0;31m[so_long deleted]\e[0;m"

re: fclean all

.PHONY: all clean fclean re