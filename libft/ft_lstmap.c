/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:24:27 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/24 14:44:46 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;

	if (lst != NULL)
	{
		res = (t_list*)malloc(sizeof(t_list));
		if (res != NULL)
		{
			res = f(lst);
			res->next = ft_lstmap(lst->next, f);
			return (res);
		}
		return (NULL);
	}
	return (NULL);
}
