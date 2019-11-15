/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_solver.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:04:36 by rabduras          #+#    #+#             */
/*   Updated: 2019/11/15 10:29:23 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function to check if tetrimino fits in a field of a certain size
*/

static int	tetriminos_fits(t_tetriminos *tetriminos, char coord, int size)
{
	if (coord == 'y')
	{
		return ((tetriminos->coords[1] + tetriminos->y_offset < size) &&
		(tetriminos->coords[3] + tetriminos->y_offset < size) &&
		(tetriminos->coords[5] + tetriminos->y_offset < size) &&
		(tetriminos->coords[7] + tetriminos->y_offset < size));
	}
	return ((tetriminos->coords[0] + tetriminos->x_offset < size) &&
	(tetriminos->coords[2] + tetriminos->x_offset < size) &&
	(tetriminos->coords[4] + tetriminos->x_offset < size) &&
	(tetriminos->coords[6] + tetriminos->x_offset < size));
}

/*
** Function to check overlaps between tetriminos
*/

static int	overlap(t_tetriminos *tetriminos, char **square)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 8)
	{
		x = tetriminos->coords[i] + tetriminos->x_offset;
		y = tetriminos->coords[i + 1] + tetriminos->y_offset;
		if (square[y][x] != '.')
			return (1);
		i += 2;
	}
	return (0);
}

/*
** Function to put tetriminos on square
*/

void		put_tetriminos(t_tetriminos *tetriminos, char **square, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 8)
	{
		x = tetriminos->coords[i] + tetriminos->x_offset;
		y = tetriminos->coords[i + 1] + tetriminos->y_offset;
		square[y][x] = letter;
		i += 2;
	}
}

/*
** Function to recursively find the solution in a field of a certain size
*/

static int	solve_in_cur_square(char **square, t_tetriminos *figure, int size)
{
	if (figure == NULL)
		return (1);
	figure->x_offset = 0;
	figure->y_offset = 0;
	while (tetriminos_fits(figure, 'y', size))
	{
		while (tetriminos_fits(figure, 'x', size))
		{
			if (!overlap(figure, square))
			{
				put_tetriminos(figure, square, figure->letter);
				if (solve_in_cur_square(square, figure->next, size))
					return (1);
				put_tetriminos(figure, square, '.');
			}
			figure->x_offset++;
		}
		figure->x_offset = 0;
		figure->y_offset++;
	}
	return (0);
}

/*
** Function to solve tetriminous.
*/

void		solve_tetriminos(t_tetriminos *tetriminos)
{
	int		size;
	char	**square;

	size = init_square_size(tetriminos);
	square = create_square(size);
	while (!solve_in_cur_square(square, tetriminos, size))
	{
		delete_square(square, size);
		square = create_square(++size);
	}
	print_square(square, size);
	delete_square(square, size);
}
