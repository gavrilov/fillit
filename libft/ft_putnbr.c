/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:46:19 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/21 16:01:26 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_recursive(int n)
{
	if (n < 10 && n > -10)
	{
		if (n > 0)
			ft_putchar(n + '0');
		else
			ft_putchar(-n + '0');
	}
	else
	{
		ft_putnbr_recursive(n / 10);
		ft_putnbr_recursive(n % 10);
	}
}

void			ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_putnbr_recursive(n);
}
