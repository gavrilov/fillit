/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:12:09 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/23 10:20:25 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*d;
	const char		*s;

	if (n == 0 || dst == src)
		return (NULL);
	i = 0;
	d = (char*)dst;
	s = (char*)src;
	c = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if ((unsigned char)d[i] == c)
			return (&dst[++i]);
		i++;
	}
	return (NULL);
}
