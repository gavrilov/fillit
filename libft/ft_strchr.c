/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:15:36 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/21 16:46:57 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	c = (char)c;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char*)&s[i]);
	return (NULL);
}
