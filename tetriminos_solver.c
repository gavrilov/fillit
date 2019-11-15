/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_solver.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:04:36 by rabduras          #+#    #+#             */
/*   Updated: 2019/11/14 15:12:15 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tetriminos_fits(t_tetriminos *tetriminos, char coord, int size)
{
	if (coord == 'y')
		return ((tetriminos->coords[1] + tetriminos->y_offset < size) &&
		(tetriminos->coords[3] + tetriminos->y_offset < size) &&
		(tetriminos->coords[5] + tetriminos->y_offset < size) &&
		(tetriminos->coords[7] + tetriminos->y_offset < size));
	return ((tetriminos->coords[0] + tetriminos->x_offset < size) &&
		(tetriminos->coords[2] + tetriminos->x_offset < size) &&
		(tetriminos->coords[4] + tetriminos->x_offset < size) &&
		(tetriminos->coords[6] + tetriminos->x_offset < size));
}

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

static int		solve_in_cur_square(char **square, t_tetriminos *tetriminos, int size)
{
	if (tetriminos == NULL)
		return (1);
	tetriminos->x_offset = 0;
	tetriminos->y_offset = 0;
	while (tetriminos_fits(tetriminos, 'y', size))
	{
		while (tetriminos_fits(tetriminos, 'x', size))
		{
			if (!overlap(tetriminos, square))
			{
				put_tetriminos(tetriminos, square, tetriminos->letter);
				if (solve_in_cur_square(square, tetriminos->next, size))
					return (1);
				put_tetriminos(tetriminos, square, '.');
			}
			tetriminos->x_offset++;
		}
		tetriminos->x_offset = 0;
		tetriminos->y_offset++;
	}
	return (0);
}

void			solve_tetriminos(t_tetriminos *tetriminos)
{
	int		size;
	char	**square;

	size = count_init_square(tetriminos);
	square = create_square(size);
	while (!solve_in_cur_square(square, tetriminos, size))
	{
		delete_square(square, size);
		square = create_square(++size);
	}
	print_square(square, size);
	delete_square(square, size);
}
