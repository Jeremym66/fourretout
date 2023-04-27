/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:44:33 by kaly              #+#    #+#             */
/*   Updated: 2023/04/19 16:45:00 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rrotate_a(t_pile *a)
{
	t_elem	*previous_last;
	t_elem	*last;

	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	previous_last = a->top;
	while (previous_last->next->next)
		previous_last = previous_last->next;
	last = a->base;
	last->next = a->top;
	a->top = last;
	a->base = previous_last;
	previous_last->next = NULL;
}

void	ft_rrotate_b(t_pile *b)
{
	t_elem	*previous_last;
	t_elem	*last;

	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	previous_last = b->top;
	while (previous_last->next->next)
		previous_last = previous_last->next;
	last = previous_last->next;
	previous_last->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	ft_rrotate_ab(t_pile *a, t_pile *b)
{
	ft_rrotate_a(a);
	ft_rrotate_b(b);
}
