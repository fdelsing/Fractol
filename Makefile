# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 22:10:04 by fdelsing          #+#    #+#              #
#    Updated: 2018/03/03 22:18:59 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = -I./includes	-I./libft/includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)
FLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = main.c ft_init_mlx.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) -L./libft/ -lft $(FLAGS) $(OBJ)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean:
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
	$(MAKE) re -C ./libft
