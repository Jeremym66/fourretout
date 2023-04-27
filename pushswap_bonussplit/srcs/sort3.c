/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 04:51:20 by kaly              #+#    #+#             */
/*   Updated: 2023/04/17 19:35:28 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort3(t_pile *pile)
{
	int	a;
	int	b;
	int	c;

	a = pile->top->gps;
	b = pile->top->next->gps;
	c = pile->top->next->next->gps;
	if (a < b && b > c && a < c)
	{
		ft_rrotate_a(pile, 1);
		ft_swap_a(pile, 1);
	}
	else if (a > b && b < c && a < c)
		ft_swap_a(pile, 1);
	else if (a < b && b > c && a > c)
		ft_rrotate_a(pile, 1);
	else if (a > b && b < c && a > c)
		ft_rotate_a(pile, 1);
	else if (a > b && b > c && a > c)
	{
		ft_swap_a(pile, 1);
		ft_rrotate_a(pile, 1);
	}
}
