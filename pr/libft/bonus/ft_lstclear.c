/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:36:26 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/04 12:59:09 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;

	if (!alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(*alst, del);
		*alst = tmp;
	}
}
