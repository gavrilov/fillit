# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 19:41:05 by kgavrilo          #+#    #+#              #
#    Updated: 2019/11/08 13:06:09 by rabduras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror -I./
SRC = main.c tetriminos_checker.c tetriminos_saver.c
LIBFT = libft/

OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc -c -o $@ $< $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	gcc $(OBJ) -o $(NAME) -L libft -lft

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re:	fclean all

build:
	rm -f $(OBJ)
	rm -f $(NAME)
	gcc $(FLAGS) -c $(SRC) -g
	gcc $(OBJ) -o $(NAME) -L libft -lft
