/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:53:10 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/28 17:25:28 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstfold(t_list *lst, int (*f)(int, int))
{
	int res;

	if (lst)
		res = *(int*)lst->content;
	else
		return (0);
	while (lst->next)
	{
		res = f(res, *(int*)lst->next->content);
		lst = lst->next;
	}
	return (res);
}
