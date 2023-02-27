/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:48:20 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/02 05:39:15 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstclear_newlist(t_list **lst,
	void (*del)(void *), void *content)
{
	if (del)
		del(content);
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *elem), void (*del)(void *))
{
	t_list	*start;
	t_list	*elem;
	t_list	*newelem;
	void	*content;

	start = NULL;
	elem = NULL;
	while (lst)
	{
		content = f(lst->content);
		newelem = ft_lstnew(content);
		if (!newelem)
			return (ft_lstclear_newlist(&start, del, content));
		if (start)
			elem->next = newelem;
		else
			start = newelem;
		elem = newelem;
		lst = lst->next;
	}
	if (elem)
		elem->next = NULL;
	return (start);
}
