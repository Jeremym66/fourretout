/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:20:17 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 19:45:25 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_a(t_pile *pile, int print)
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
	if (print == 1)
		write(1, "sa\n", 3);
	else
		write(1, "ss\n", 3);
}

void	ft_swap_b(t_pile *pile, int print)
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
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ft_swap_ab(t_pile *a, t_pile *b)
{
	ft_swap_a(a, 2);
	ft_swap_b(b, 2);
}
