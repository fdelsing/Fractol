# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 22:10:04 by fdelsing          #+#    #+#              #
#    Updated: 2018/03/05 23:02:47 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = -I./includes	-I./libft/includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)
FLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = main.c ft_init_mlx.c ft_put_pixel.c mandelbrot.c keyhook.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) -L./libft/ -lft $(FLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)

libclean:
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)

libfclean:
	$(MAKE) fclean -C ./libft

re: fclean all

libre:
	$(MAKE) re -C ./libft
