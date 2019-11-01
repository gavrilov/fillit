# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 19:41:05 by kgavrilo          #+#    #+#              #
#    Updated: 2019/11/01 14:12:58 by rabduras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror -I./
SRC = main.c
OBJ = main.o

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
