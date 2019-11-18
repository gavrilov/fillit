/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:20:54 by rabduras          #+#    #+#             */
/*   Updated: 2019/11/18 13:57:43 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_remained_chars(char **remained, char **line, int fd, char *buff)
{
	int		len;
	char	*temp;

	len = -1;
	temp = ft_strnew(0);
	if (remained[fd] != NULL)
	{
		ft_strdel(&temp);
		temp = ft_strdup(remained[fd]);
		ft_strdel(&remained[fd]);
	}
	remained[fd] = ft_strjoin(temp, buff);
	ft_strdel(&temp);
	while (remained[fd][++len] && remained[fd][len] != '\n')
		;
	if (remained[fd][len] == '\n')
	{
		*line = ft_strsub(remained[fd], 0, len);
		temp = ft_strsub(remained[fd], ++len, ft_strlen(remained[fd]));
		ft_strdel(&remained[fd]);
		remained[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			br;
	static char	*remained[FD_SIZE];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || (read(fd, buff, 0)) < 0)
		return (-1);
	while ((br = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[br] = '\0';
		if (get_remained_chars(remained, line, fd, buff))
			return (1);
	}
	if (remained[fd] != NULL && *remained[fd])
	{
		if (!get_remained_chars(remained, line, fd, ""))
		{
			*line = ft_strdup(remained[fd]);
			ft_strdel(&remained[fd]);
		}
		return (1);
	}
	ft_strdel(&remained[fd]);
	return (br);
}
