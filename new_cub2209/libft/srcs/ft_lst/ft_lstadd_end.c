/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:57:52 by angavrel          #+#    #+#             */
/*   Updated: 2023/04/12 10:01:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_end(t_list **last, t_list *new)
{
	if ((*last)->next != NULL)
		ft_lstadd_end(&(*last)->next, new);
	else
	{
		(*last)->next = new;
	}
}
