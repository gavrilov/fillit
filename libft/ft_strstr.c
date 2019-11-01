/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:42:01 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/23 11:14:09 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int len;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	len = ft_strlen((char*)needle);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
			if (ft_strncmp(&haystack[i], needle, len) == 0)
				return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
