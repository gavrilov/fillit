/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:41:37 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/06 22:35:47 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Function to check length of string
** Return True if it is 4 char str or new line on 5th line
*/

static int		check_length(char *line, int count_lines)
{
	int		len;

	len = ft_strlen(line);
	if ((len == 0 && count_lines % 5 == 0) ||
	(len == 4 && count_lines % 5 != 0))
		return (1);
	return (0);
}

/*
** Function to check chars of string
** Return True if all chars are # and dots
*/

static int		check_chars(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}

static int		check_figure(char *line, int *hashes, int *min, int *max)
{
	int i;
	int temp;
	int in_range;

	i = -1;
	temp = -1;
	in_range = 0;
	while (++i < 4)
	{
		if (line[i] == '#')
		{
			if (*hashes == 0 || (i >= *min && i <= *max && temp == -1)
			|| (i >= *min && i <= *max && temp == i))
				in_range = 1;
			else if (temp != -1 && temp != i)
				return (0);
			if (temp == -1)
				*min = i;
			temp = i + 1;
			*hashes += 1;
		}
	}
	*max = temp - 1;
	return ((in_range == *hashes || in_range
	|| (*hashes == 4 && temp == -1)) && *hashes < 5);
}

/*
** Function to validate Tetriminos file
** Return True if it is correct
*/

int				check_tetriminos_file(char *filename)
{
	int		fd;
	char	*line;
	int		count_lines;
	int		hashes;
	int		range[2];

	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		line = NULL;
		range[0] = 0;
		range[1] = 0;
		hashes = 0;
		while (get_next_line(fd, &line) > 0)
		{
			if (!(check_length(line, ++count_lines) && check_chars(line)))
				return (0);
			if (count_lines % 5 == 0)
			{
				hashes = 0;
				continue;
			}
			if (!(check_figure(line, &hashes, &range[0], &range[1])))
				return (0);
		}
	}
	close(fd);
	return (0);
}
