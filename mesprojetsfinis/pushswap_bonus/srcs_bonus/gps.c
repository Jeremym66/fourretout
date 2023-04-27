/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:00:45 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 19:35:40 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_gps(t_pile *pile)
{
	t_elem	*a;
	t_elem	*b;

	a = pile->top;
	b = a->next;
	while (a->next != NULL)
	{
		while (b != NULL)
		{
			if (a->nb > b->nb)
				a->gps++;
			else
				b->gps++;
			b = b->next;
		}
		a = a->next;
		b = a->next;
	}
	pile->gps_max = pile->nb_element;
}
