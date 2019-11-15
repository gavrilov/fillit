/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:55:21 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/14 15:16:27 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_tetriminos
{
	int					coords[8];
	char				letter;
	int					x_offset;
	int					y_offset;
	struct s_tetriminos	*next;
}						t_tetriminos;

char					*check_tetriminos_file(char *filename);
t_tetriminos			*save_tetriminos(char *str);
void					solve_tetriminos(t_tetriminos *tetriminos);
void					delete_square(char **square, int size);
void					delete_tetriminos(t_tetriminos *tetriminos);
char					**create_square(int size);
int						count_init_square(t_tetriminos *tetriminos);
void					print_square(char **square, int size);

#endif
