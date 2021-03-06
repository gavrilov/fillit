/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:55:21 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/28 16:37:03 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct			s_tetriminos
{
	int					coords[8];
	char				letter;
	int					x_offset;
	int					y_offset;
	struct s_tetriminos	*next;
}						t_tetriminos;

char					*check_tetriminos_file(char *filename);
char					**create_square(int size);
void					delete_square(char **square, int size);
void					delete_tetriminos(t_tetriminos *tetriminos);
int						init_square_size(t_tetriminos *tetriminos);
void					print_square(char **square, int size);
t_tetriminos			*save_tetriminos(char *str);
int						solve_tetriminos(t_tetriminos *tetriminos);

#endif
