/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:32:21 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/28 11:17:07 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		ft_strncpy(str, &s[start], len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
