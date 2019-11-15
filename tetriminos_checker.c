/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:41:37 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/14 16:07:50 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
** Function to validate Tetriminos
** Return True if it is correct figure
*/

static int		check_figure(char *line, char *res, int *hashes, int lines)
{
	int c;
	int	len;

	len = -1;
	c = (lines - 1 % 5 == 0) ? lines - 2 : lines - 1;
	while (line[++len])
	{
		if (line[len] != '#' && line[len] != '.')
			return (0);
		if (line[len] == '#')
		{
			(*hashes)++;
			if (res[c * 4 - len] != '#' && line[len - 1] != '#' && hashes == 0)
				return (0);
		}
	}
	if (lines % 5 == 0 && *hashes != 4)
		return (0);
	if (lines % 5 == 0 && *hashes == 4)
		*hashes = 0;
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
	int		hashes;
	int		lines;
	char	*line;
	char	*res;

	fd = open(filename, O_RDONLY);
	if (fd < 2)
		return (NULL);
	hashes = 0;
	lines = 0;
	res = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_figure(line, res, &hashes, ++lines))
		{
			ft_strdel(&res);
			return (NULL);
		}
		res = join_lines(line, res);
		ft_strdel(&line);
	}
	close(fd);
	return (res);
}
