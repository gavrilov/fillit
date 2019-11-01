/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:07:08 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/24 15:32:55 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		d_length;

	d = dst;
	s = src;
	n = dstsize;
	while (*d != '\0' && n-- != 0)
		d++;
	d_length = d - dst;
	n = dstsize - d_length;
	if (n == 0)
		return (d_length + ft_strlen((char*)s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (d_length + (s - src));
}
