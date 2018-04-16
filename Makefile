# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 22:10:04 by fdelsing          #+#    #+#              #
#    Updated: 2018/04/16 19:50:21 by fdelsing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = -I./includes	-I./libft/includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)
MLX = -lmlx -framework OpenGL -framework Appkit

SRC = ./srcs/main.c		./srcs/ft_init_mlx.c	./srcs/ft_put_pixel.c \
	  ./srcs/mandelbrot.c	./srcs/julia.c		./srcs/burningship.c \
	  ./srcs/bonus_multibrot.c	./srcs/bonus_sierpinski.c	./srcs/hook.c \
	  ./srcs/fractals.c	./srcs/bonus_keyzoom.c	./srcs/bonus_bacteria.c \
	  ./srcs/bonus_tricorn.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c includes/
	$(CC) $(FLAGS) -c -o $@ $<

#libft/libft.a: libft/src
#	make -C libft/

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) -L./libft/ -lft $(MLX) $(OBJ)

clean:
	rm -rf $(OBJ)

libclean:
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)

libfclean:
	$(MAKE) fclean -C ./libft

re: 
	$(MAKE) fclean
	$(MAKE) all

libre:
	$(MAKE) re -C ./libft
