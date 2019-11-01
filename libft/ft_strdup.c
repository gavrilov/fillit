/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:12:10 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/26 15:11:29 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char*)(malloc(sizeof(char) * (ft_strlen(src) + 1)));
	if (str != NULL)
		str = ft_strcpy(str, src);
	return (str);
}
