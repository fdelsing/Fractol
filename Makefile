# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 22:10:04 by fdelsing          #+#    #+#              #
#    Updated: 2018/03/06 17:22:29 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = -I./includes	-I./libft/includes
CC = gcc
#CFLAGS = -Wall -Wextra -Werror $(HEADER)
CFLAGS = $(HEADER)
FLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = main.c ft_init_mlx.c ft_put_pixel.c mandelbrot.c hook.c

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

#######################

makesan:
	gcc -fsanitize=address -g -L./libft/ -lft $(FLAGS) $(HEADER) $(SRC)
