/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:40:57 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/01 14:07:18 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: fillit file");
	}
	else
	{
		ft_putendl(argv[1]);
	}
	return (0);
}
