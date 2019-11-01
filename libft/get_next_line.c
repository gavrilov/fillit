/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgavrilo <kgavrilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:08:43 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/01 15:11:56 by kgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*check_rmndr(char *rmndr, char **line)
{
	char	*p_nl;

	p_nl = NULL;
	if (rmndr)
		if ((p_nl = ft_strchr(rmndr, '\n')))
		{
			*p_nl = '\0';
			*line = ft_strdup(rmndr);
			ft_strcpy(rmndr, ++p_nl);
		}
		else
		{
			*line = ft_strdup(rmndr);
			ft_strclr(rmndr);
		}
	else
		*line = ft_strnew(1);
	return (p_nl);
}

int				get_line(const int fd, char **line, char **rmndr)
{
	char			buf[BUFF_SIZE + 1];
	int				n;
	char			*p_nl;
	char			*tmp;

	if (read(fd, buf, 0) < 0)
		return (-1);
	p_nl = check_rmndr(*rmndr, line);
	while (!p_nl && (n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		if ((p_nl = ft_strchr(buf, '\n')))
		{
			*p_nl = '\0';
			*rmndr = ft_strdup(++p_nl);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || n < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (n || p_nl || ft_strlen(*line)) ? 1 : 0;
}

t_fd_list		*new_list(int fd)
{
	t_fd_list		*new;

	new = (t_fd_list *)malloc(sizeof(t_fd_list));
	new->fd = fd;
	new->rmndr = NULL;
	new->next = NULL;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd_list	*head;
	t_fd_list			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (head == NULL)
		head = new_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->rmndr));
}
