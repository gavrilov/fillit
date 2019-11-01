/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:31:55 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/29 12:04:41 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_joinstrs(char *des, char **src, char *delimeter, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	des[j++] = *delimeter;
	while (i < size)
	{
		while (*src[i])
		{
			des[j++] = *src[i];
			src[i]++;
		}
		des[j++] = *delimeter;
		i++;
	}
	des[j] = '\0';
	return (des);
}

char		*ft_strconcat(char **str, char *delimeter, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	if (size <= 0)
		return (NULL);
	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j++])
			len++;
		i++;
	}
	res = (char*)malloc(sizeof(char) * (len + size + 1));
	if (res != NULL)
		return (ft_joinstrs(res, str, delimeter, size));
	return (NULL);
}
