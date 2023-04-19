/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:19:31 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 19:45:10 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_a(t_pile *a, t_pile *b)
{
	t_elem	*firsta;
	t_elem	*btoa;
	t_elem	*secondb;

	if (a == NULL || b == NULL || b->top == NULL)
		return ;
	firsta = a->top;
	btoa = b->top;
	secondb = btoa->next;
	a->top = btoa;
	b->top = secondb;
	btoa->next = firsta;
	write(1, "pa\n", 3);
	b->nb_element--;
	a->nb_element++;
}

void	ft_push_b(t_pile *a, t_pile *b)
{
	t_elem	*firstb;
	t_elem	*atob;
	t_elem	*seconda;

	if (a == NULL || b == NULL || a->top == NULL)
		return ;
	firstb = b->top;
	atob = a->top;
	seconda = atob->next;
	b->top = atob;
	a->top = seconda;
	atob->next = firstb;
	write(1, "pb\n", 3);
	a->nb_element--;
	b->nb_element++;
}
