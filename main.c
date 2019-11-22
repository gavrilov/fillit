/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:40:57 by kgavrilo          #+#    #+#             */
/*   Updated: 2019/11/21 16:28:44 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char			*res;
	t_tetriminos	*tetriminos;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (1);
	}
	if ((res = check_tetriminos_file(argv[1])) == NULL)
	{
		ft_putendl("error");
		exit(1);
		return (1);
	}
	tetriminos = save_tetriminos(res);
	ft_strdel(&res);
	if (!solve_tetriminos(tetriminos))
	{
		delete_tetriminos(tetriminos);
		ft_putendl("error");
		return (1);
	}
	delete_tetriminos(tetriminos);
	return (0);
}
