/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:22:00 by rabduras          #+#    #+#             */
/*   Updated: 2019/11/15 10:37:17 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function to count tetriminous
*/

static int	count_tetriminos(t_tetriminos *tetriminos)
{
	int		figures;

	figures = 0;
	while (tetriminos)
	{
		figures++;
		tetriminos = tetriminos->next;
	}
	return (figures);
}

/*
** Function to delete square
*/

void		delete_square(char **square, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_strdel(&square[i]);
	ft_strdel(square);
}

/*
** Function to create square
*/

char		**create_square(int size)
{
	int		i;
	char	**square;

	i = -1;
	if ((square = (char**)malloc(sizeof(char*) * size)) == NULL)
		return (NULL);
	while (++i < size)
	{
		if ((square[i] = (char*)malloc(sizeof(char) * size)) == NULL)
			return (NULL);
		ft_memset(square[i], '.', size);
	}
	return (square);
}

/*
** Function to find size of initial field
*/

int			init_square_size(t_tetriminos *tetriminos)
{
	int		figures;
	int		square_size;

	square_size = 2;
	figures = count_tetriminos(tetriminos);
	while (square_size * square_size < figures * 4)
		square_size++;
	return (square_size);
}

/*
** Function to print square
*/

void		print_square(char **square, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(square[i][j]);
		ft_putchar('\n');
	}
}
