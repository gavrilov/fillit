/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:58:08 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/21 16:02:38 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_recursive(int n, int fd)
{
	if (n < 10 && n > -10)
	{
		if (n > 0)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(-n + '0', fd);
	}
	else
	{
		ft_putnbr_recursive(n / 10, fd);
		ft_putnbr_recursive(n % 10, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_recursive(n, fd);
}
