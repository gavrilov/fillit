/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:44:21 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/21 15:02:15 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	return (NULL);
}
