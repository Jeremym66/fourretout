/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:20:17 by kaly              #+#    #+#             */
/*   Updated: 2023/04/19 16:45:35 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_a(t_pile *pile)
{
	t_elem	*first;
	t_elem	*second;
	t_elem	*third;

	if (pile == NULL || pile->top == NULL || pile->top->next == NULL)
		return ;
	first = pile->top;
	second = first->next;
	third = second->next;
	pile->top = second;
	second->next = first;
	first->next = third;
}

void	ft_swap_b(t_pile *pile)
{
	t_elem	*first;
	t_elem	*second;
	t_elem	*third;

	if (pile == NULL || pile->top == NULL || pile->top->next == NULL)
		return ;
	first = pile->top;
	second = first->next;
	third = second->next;
	pile->top = second;
	second->next = first;
	first->next = third;
}

void	ft_swap_ab(t_pile *a, t_pile *b)
{
	ft_swap_a(a);
	ft_swap_b(b);
}
