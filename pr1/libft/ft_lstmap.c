/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:31:36 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:46:52 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*results;
	t_list	*origin;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	origin = NULL;
	while (lst)
	{
		results = ft_lstnew(f(lst->content));
		if (results == NULL)
		{
			ft_lstdelone(results, del);
			return (NULL);
		}
		ft_lstadd_back(&origin, results);
		lst = lst->next;
	}
	return (origin);
}
