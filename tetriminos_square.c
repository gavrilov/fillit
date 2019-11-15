/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:22:00 by rabduras          #+#    #+#             */
/*   Updated: 2019/11/13 19:12:50 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_tetriminos(t_tetriminos *tetriminos)
{
	int figures;

	figures = 0;
	while (tetriminos)
	{
		figures++;
		tetriminos = tetriminos->next;
	}
	return (figures);
}

void		delete_square(char **square, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_strdel(&square[i]);
	ft_strdel(square);
}

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

int		count_init_square(t_tetriminos *tetriminos)
{
	int figures;
	int init_square;

	init_square = 2;
	figures = count_tetriminos(tetriminos);
	while (init_square * init_square < figures * 4)
		init_square++;
	return (init_square);
}

void	print_square(char **square, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(square[i][j]);
		ft_putchar('\n');
	}
}
