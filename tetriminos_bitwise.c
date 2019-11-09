/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_bitwise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:19:12 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/08 18:58:03 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

/*
**	List of tetriminos
**	First struct is solution
*/

typedef struct s_tetrimino
{
	long long			data;
	struct s_tetrimino	*next;

} t_tetrimino;

/*
**	Create list of tetriminos
*/

t_tetrimino *create_list(long long data)
{
	t_tetrimino *res;

	res = malloc(sizeof(t_tetrimino));
	res->next = NULL;
	res->data = data;
	return (res);
}

/*
**	Test data
*/

t_tetrimino	*three_lists(void)
{
	t_tetrimino *list;

	list = create_list(3758);
	list->next = create_list(35008);
	list->next->next = create_list(25120);
	return(list);
}

/*
**	Long Long to Char
*/

char		*figure_long2char(long long figure, char fig)
{
	int		i;
	int		j;
	char	*result;

	j = 0;
	i = 32768;

	result = ft_strnew(16);
	while (i > 0)
	{
		if (i & figure)
			result[j] = fig;
		else
			result[j] = '.';
		i >>= 1;
		j++;
	}
	result[j] = '\0';
	return (result);
}

/*
**	To generate map from list of figures
**	Firures must be offset correctly
*/

char		*generate_map(t_tetrimino *tetrimino_list)
{
	char	letter;
	int		i;
	int		j;
	char	*map;
	char	*figure;

	letter = 'A';
	map = ft_strnew(16); // for 4*4 map
	figure = ft_strnew(16);
	i = 0;
	tetrimino_list = tetrimino_list->next;
	while (tetrimino_list)
	{
		i = 0;
		figure = figure_long2char(tetrimino_list->data, letter);
		while (figure[i] != '\0')
		{
			if (figure[i] != '.')
				map[i] = figure[i];
			if (map[i] == '\0')
				map[i] = '.';
			i++;
		}
		map[i] = '\n';
		i++;
		tetrimino_list = tetrimino_list->next;
		letter++;
	}
	return (map);
}

/*
**	To print map of map_size
*/

void	print_map(char *map, int map_size)
{
	int i;

	i = 0;
	while(*map)
	{
		if (i == map_size)
		{
			write(1, "\n", 1);
			i = 0;
		}
		write(1, map, 1);
		i++;
		map++;
	}
	write(1, "\n", 1);
}

/*
** Convert figure to bits and calculate offset
** to move it to upper left corner
** Take 4*4 figure and write it in reverse
*/

long long		figure_char2long(char *figure)
{
	int			i;
	int			j; // use for count minimum offset
	int			offset;
	int			mask;
	long long	result;

	i = 15;
	result = 0;
	j = 3;

	offset = 3; // максимальное смещение для поля 4*4 == 3
	while (i >= 0)
	{
		result = result >> 1; // сместить переменную и если # то применить маску 1 000 000 000 000 000 (dec = 32768)
		if (figure[i] == '#')
		{
			if (offset > j) // если нашли # ближе чем текушее смещение
				offset = j;
			result = result | 32768; // записываем единицу
		}
		if (--j)
			j = 4;
		i--;
	}
	return(result << offset); // return with offset
}

int		main(void)
{
	char		*fig;
	char		*result;
	long long	test1;

	fig = ft_strdup("...#...#...#...#"); // set the figure
	test1 = figure_char2long(fig); // convert to long and offset to left upper corner
	result = figure_long2char(test1, 'E'); // convert to char, replace with letter

	print_map(result, 4); //print figure
	printf("\ntest with 3 lists:\n\n");
	print_map(generate_map(three_lists()), 4); // test data from lists
	return (0);
}
