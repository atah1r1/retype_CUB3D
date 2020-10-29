# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 10:43:07 by atahiri           #+#    #+#              #
#    Updated: 2020/10/29 11:03:13 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.a
AR = ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c gnl_function/*.c libft_functions/*.c

all:$(NAME)

$(NAME):
	$(CC) -o Cub3d  -framework OpenGL -framework AppKit -l mlx $(SRC) -g
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all