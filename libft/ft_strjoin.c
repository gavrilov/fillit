/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:51:56 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/29 12:10:51 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char*)s1);
	s2_len = ft_strlen((char*)s2);
	str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str != NULL)
	{
		ft_strncpy(str, s1, s1_len);
		ft_strncpy(&str[s1_len], s2, s2_len);
		str[s1_len + s2_len] = '\0';
		return (str);
	}
	return (NULL);
}
