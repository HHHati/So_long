# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 14:20:24 by bade-lee          #+#    #+#              #
#    Updated: 2022/03/13 15:28:05 by bade-lee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#           ----------========== {     VARS     } ==========----------

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I include

#           ----------========== {     CHAR     } ==========----------

SRC =\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_tolower.c\
	ft_toupper.c

#           ----------========== {     LIST     } ==========----------

SRC +=\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c

#           ----------========== {    MEMORY    } ==========----------
SRC +=\
	ft_bzero.c\
	ft_calloc.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c

#           ----------========== {    NUMRIC    } ==========----------
SRC +=\
	ft_atoi.c\
	ft_itoa.c

#           ----------========== {    PRINTS    } ==========----------
SRC +=\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c

#           ----------========== {    STRING    } ==========----------
SRC +=\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c

#           ----------========== {     GNL      } ==========----------
SRC +=\
	get_next_line.c\
	get_next_line_utils.c\

#           ----------========== {    PRINTF    } ==========----------
SRC +=\
	1_param_c.c\
	2_param_s.c\
	3_param_p.c\
	4_param_d.c\
	5_param_i.c\
	6_param_u.c\
	7_param_x.c\
	8_param_X.c\
	9_param_%.c\
	ft_printf.c\

#           ----------========== {     OBJS     } ==========----------

SRC_DIR = src/
OBJ_DIR = obj_libft/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

VPATH= $(shell find $(SRC_DIR) -type d)

#           ----------========== {    REGLES    } ==========----------

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	@printf "\e[1;32m.\e[0;m"

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re