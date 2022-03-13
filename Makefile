# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 16:19:10 by bade-lee          #+#    #+#              #
#    Updated: 2022/03/13 13:32:06 by bade-lee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#          ----------========== {     VARS     } ==========----------

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I includes/

#          ----------========== {     SRCS     } ==========----------

SRC = \

#          ----------========== {   SRCS LIB   } ==========----------

SRC += \

#          ----------========== {     OBJS     } ==========----------

SRC_DIR = src/
OBJ_DIR = obj_$(NAME)/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

VPATH= $(shell find $(SRC_DIR) -type d)

#          ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $(NAME)
	@printf "\e[1;32m.\e[0;m"

$(NAME): $(OBJ_DIR) $(OBJ)
	@printf "\n\e[1;32m[So_long]\e[0;m\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "\e[1;32mCreate $(OBJ_DIR)]\e[0;m\n"

exe: all
	@$(CC) $(FLAGS) $(INCLUDE) $(NAME) main.c
	@./a.out

clean:
	@rm -f $(OBJ)
	@printf "\e[31m[*.o files deleted]\e[0;m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[31m[So_long deleted]\e[0;m\n"

re: fclean all

.PHONY: all clean fclean re