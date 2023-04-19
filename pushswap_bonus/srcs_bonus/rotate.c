/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:05:51 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 19:45:40 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_a(t_pile *a, int print)
{
	t_elem	*first;
	t_elem	*last;

	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	first = a->top;
	last = a->base;
	a->top = first->next;
	last->next = first;
	a->base = first;
	first->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rr\n", 3);
}

void	ft_rotate_b(t_pile *b, int print)
{
	t_elem	*first;
	t_elem	*last;

	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	first = b->top;
	last = b->top;
	while (last->next)
		last = last->next;
	b->top = first->next;
	last->next = first;
	first->next = NULL;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_pile *a, t_pile *b)
{
	ft_rotate_a(a, 2);
	ft_rotate_b(b, 2);
}
