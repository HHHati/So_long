# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 16:19:10 by bade-lee          #+#    #+#              #
#    Updated: 2022/04/28 11:49:10 by Basile19         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address
INCLUDE = -I so_long.h
LIB = libft/libft.a
MLX = minilibx/libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit

#          ----------========== {     SRCS     } ==========----------

SRC =	src/main.c\
		src/check_map.c\
		src/end.c\
		src/init.c\
		src/window.c

#          ----------========== {     OBJS     } ==========----------

OBJ = $(SRC:.c=.o)

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -sC minilibx
	@$(CC) $(FLAGS) $(MLXFLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)
	@printf "\e[1;32m[So_long]\e[0;m"

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@printf "\e[1;32m.\e[0;m"

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@printf "\e[0;31m[.o files deleted]\e[0;m"

fclean: clean
	@make -C libft fclean
	@make -C minilibx clean
	@rm -f $(NAME)
	@printf "\e[0;31m[So_long deleted]\e[0;m"

re: fclean all

.PHONY: all clean fclean re