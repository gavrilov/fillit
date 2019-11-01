/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabduras <rabduras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:17:25 by rabduras          #+#    #+#             */
/*   Updated: 2019/09/23 16:30:41 by rabduras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list != NULL)
	{
		list->next = NULL;
		if (content == NULL)
		{
			list->content_size = 0;
			return (list);
		}
		else
			list->content_size = content_size;
		list->content = malloc(content_size);
		ft_memmove(list->content, content, content_size);
		return (list);
	}
	return (NULL);
}
