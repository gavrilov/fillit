# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgavrilo <kgavrilo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 19:41:05 by kgavrilo          #+#    #+#              #
#    Updated: 2019/11/06 19:52:17 by kgavrilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror -I./
SRC = main.c tetriminos_checker.c
OBJ = main.o tetriminos_checker.o

all: $(NAME)

$(NAME):
	cd ./libft && make
	gcc $(FLAGS) -c $(SRC)
	gcc $(OBJ) -o $(NAME) -L libft -lft

clean:
	cd ./libft && make clean
	rm -f $(OBJ)

fclean: clean
	cd ./libft && make fclean
	rm -f $(NAME)

re:	fclean all

build:
	rm -f $(OBJ)
	rm -f $(NAME)
	gcc $(FLAGS) -c $(SRC) -g
	gcc $(OBJ) -o $(NAME) -L libft -lft
