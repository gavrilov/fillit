/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:48:02 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/21 18:16:46 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int last_index;

	i = 0;
	last_index = -1;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			last_index = i;
		i++;
	}
	if (c == '\0')
		return ((char*)&s[i]);
	if (last_index != -1)
		return ((char*)&s[last_index]);
	return (NULL);
}
