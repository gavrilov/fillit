/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:19:09 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/28 11:19:27 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen((char*)s);
	while (is_space(s[i++]))
		start = i;
	while (is_space(s[end - 1]) && start != end)
		end--;
	str = (char*)malloc(sizeof(char) * (end - start + 1));
	if (str != NULL)
	{
		i = 0;
		while (start < end)
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
