/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_saver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:02:07 by rabduras          #+#    #+#             */
/*   Updated: 2019/11/14 20:09:22 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void					delete_tetriminos(t_tetriminos *tetriminos)
{
	t_tetriminos *temp;

	while (tetriminos)
	{
		temp = tetriminos->next;
		ft_memdel((void **)&(tetriminos));
		tetriminos = temp;
	}
}

static t_tetriminos		*align_top_left(t_tetriminos *tetriminos)
{
	int i;
	int	x_min;
	int	y_min;

	i = 2;
	x_min = tetriminos->coords[0];
	y_min = tetriminos->coords[1];
	while (i < 8)
	{
		if (x_min > tetriminos->coords[i])
			x_min = tetriminos->coords[i];
		if (y_min > tetriminos->coords[i + 1])
			y_min = tetriminos->coords[i + 1];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		tetriminos->coords[i] = tetriminos->coords[i] - x_min;
		tetriminos->coords[i + 1] = tetriminos->coords[i + 1] - y_min;
		i += 2;
	}
	return (tetriminos);
}

static t_tetriminos		*create_tetriminos(char *str, char letter)
{
	int				i;
	int				x;
	int				y;
	t_tetriminos	*tetriminos;

	if (!(tetriminos = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
		return (NULL);
	i = -1;
	x = 0;
	y = 1;
	tetriminos->next = NULL;
	tetriminos->letter = letter;
	while (++i < 16)
	{
		if (str[i] == '#')
		{
			tetriminos->coords[x] = i % 4;
			tetriminos->coords[y] = i / 4;
			x += 2;
			y += 2;
		}
	}
	return (align_top_left(tetriminos));
}

t_tetriminos			*save_tetriminos(char *str)
{
	int				i;
	char			letter;
	t_tetriminos	*first;
	t_tetriminos	*current;

	i = 0;
	letter = 'A';
	while (*str)
	{
		if (letter == 'A')
		{
			first = create_tetriminos(str, letter++);
			current = first;
		}
		else
		{
			current->next = create_tetriminos(str, letter++);
			current = current->next;
		}
		str += 16;
	}
	return (first);
}
