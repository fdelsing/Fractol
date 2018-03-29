# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 22:10:04 by fdelsing          #+#    #+#              #
#    Updated: 2018/03/29 17:50:48 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = -I./includes	-I./libft/includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)
#CFLAGS = $(HEADER)
FLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = ./srcs/main.c		./srcs/ft_init_mlx.c	./srcs/ft_put_pixel.c \
	  ./srcs/mandelbrot.c	./srcs/julia.c		./srcs/burningship.c \
	  ./srcs/multibrot.c	./srcs/sierpinski.c		./srcs/hook.c \
	  ./srcs/fractals.c		./srcs/bonus_keyzoom.c		./srcs/bla.c

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
