/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:41:37 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/15 09:55:05 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function to connect lines to each other
** Return line
*/

static char		*join_lines(char *line, char *prevlines)
{
	char *temp;

	temp = ft_strdup(prevlines);
	ft_strdel(&prevlines);
	prevlines = ft_strjoin(temp, line);
	ft_strdel(&temp);
	return (prevlines);
}

/*
** Function to check connections of # with other #
**
*/

static int		c_connects(char *str)
{
	int i;
	int connects;

	i = -1;
	connects = 0;
	while (++i < 16)
	{
		if (str[i] == '#')
		{
			if (i != 0 && str[i - 1] == '#')
				connects++;
			if (i + 1 < 16 && str[i + 1] == '#')
				connects++;
			if (i >= 4 && str[i - 4] == '#')
				connects++;
			if (i + 4 < 16 && str[i + 4] == '#')
				connects++;
		}
	}
	return (connects == 6 || connects == 8);
}

/*
** Function to validate Tetriminos
** Return True if it is correct figure
*/

static int		check_figure(char *line, char *res, int *hashes, int lines)
{
	int	len;

	len = -1;
	while (line[++len])
	{
		if (line[len] != '#' && line[len] != '.')
			return (0);
		if (line[len] == '#')
			(*hashes)++;
	}
	if (lines % 5 == 0 && *hashes != 4)
		return (0);
	if (lines % 5 == 0 && *hashes == 4)
	{
		if (c_connects(&res[ft_strlen(res) - 16]) == 0)
			return (0);
		*hashes = 0;
	}
	if ((len == 0 && lines % 5 == 0) || (len == 4 && lines % 5 != 0))
		return (1);
	return (0);
}

/*
** Function to validate Tetriminos file
** Return NULL if its problem with the
** file or file was incorrect
*/

char			*check_tetriminos_file(char *filename)
{
	int		fd;
	int		counters[2];
	char	*line;
	char	*res;

	fd = open(filename, O_RDONLY);
	if (fd < 2)
		return (NULL);
	counters[0] = 0;
	counters[1] = 0;
	res = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_figure(line, res, &counters[1], ++counters[0]))
		{
			ft_strdel(&res);
			return (NULL);
		}
		res = join_lines(line, res);
		ft_strdel(&line);
	}
	close(fd);
	if (++counters[0] % 5 != 0 || c_connects(&res[ft_strlen(res) - 16]) == 0)
		return (NULL);
	return (res);
}
