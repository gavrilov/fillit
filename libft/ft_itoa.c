/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 09:22:08 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/22 16:32:51 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_rec(int n, char *str, int i)
{
	if (n < 10 && n > -10)
	{
		if (n > 0)
			str[i] = n + '0';
		else
			str[i] = -n + '0';
		i++;
	}
	else
	{
		i = ft_itoa_rec(n / 10, str, i);
		i = ft_itoa_rec(n % 10, str, i);
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		nbr;
	int		size;
	char	*str;

	size = 1;
	nbr = n;
	while (nbr > 10 || nbr < -10)
	{
		size++;
		nbr = nbr / 10;
	}
	if (n < 0)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
	{
		i = 0;
		if (n < 0)
			str[i++] = '-';
		i = ft_itoa_rec(n, str, i);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
