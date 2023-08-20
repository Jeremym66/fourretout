/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:28:00 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/10 09:02:55 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*changed_list;
	t_list	*changed_elem;

	changed_list = NULL;
	while (lst)
	{
		changed_elem = ft_lstnew(f(lst->content));
		if (!changed_elem)
		{
			ft_lstclear(&changed_list, del);
			return (NULL);
		}
		ft_lstadd_back(&changed_list, changed_elem);
		lst = lst->next;
	}
	return (changed_list);
}
