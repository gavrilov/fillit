/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:17:08 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/20 17:45:50 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char*)s;
	c = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c)
			return (void*)(&str[i]);
		i++;
	}
	return (NULL);
}
