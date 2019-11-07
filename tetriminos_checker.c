/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:41:37 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/06 19:21:35 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Function to validate Tetriminos file
** Return True if it is correct
*/

int		check_tetriminos_file(char *filename)
{
	int		fd;
	char	*line;
	int		count_lines;

	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		line = NULL;
		while (get_next_line(fd, &line) > 0)
		{
			count_lines++;
			if (!(check_length(line, count_lines) && check_chars(line)))
				return (0);
			// if (!(check_figure())) // wait for John
			//  	return (0);
		}
	}
	close(fd);
	return (0);
}

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
