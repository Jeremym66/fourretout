/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 04:32:34 by kaly              #+#    #+#             */
/*   Updated: 2023/04/17 19:35:02 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_div(t_pile *a, t_pile *b, int div, int rest)
{
	int		i;

	i = a->gps_max;
	while (a->nb_element > div)
	{
		if (a->top->gps <= i - div)
		{
			ft_push_b(a, b);
			if (b->nb_element >= 2)
			{
				if (b->top->gps < i - div - (rest - div) / 2
					&& a->top->gps > i - div)
					ft_rotate_ab(a, b);
				else if (b->top->gps < i - div - (rest - div) / 2)
					ft_rotate_b(b, 1);
			}
		}
		else
			ft_rotate_a(a, 1);
	}
}

void	ft_check_near(t_pile *a, t_pile *b)
{
	int		i;
	int		y;
	t_elem	*check;

	while (b->nb_element != 0)
	{
		i = 0;
		y = b->nb_element;
		check = b->top;
		while (b->nb_element != check->gps)
		{
			check = check->next;
			i++;
			y--;
		}
		if (i <= y)
		{
			while (i-- != 0)
				ft_rotate_b(b, 1);
		}
		else
			while (y-- != 0)
				ft_rrotate_b(b, 1);
		ft_push_a(a, b);
	}
}

void	ft_sort10(t_pile *a, t_pile *b)
{
	ft_div(a, b, 6, 10);
	ft_div(a, b, 3, 6);
	ft_sort3(a);
	ft_check_near(a, b);
}

void	ft_sort100(t_pile *a, t_pile *b)
{
	ft_div(a, b, 70, a->gps_max);
	ft_div(a, b, 45, 70);
	ft_div(a, b, 22, 45);
	ft_div(a, b, 10, 22);
	ft_sort10(a, b);
}

void	ft_sort_max(t_pile *a, t_pile *b)
{
	ft_div(a, b, 400, a->gps_max);
	ft_div(a, b, 320, 400);
	ft_div(a, b, 256, 320);
	ft_div(a, b, 204, 256);
	ft_div(a, b, 163, 204);
	ft_div(a, b, 115, 163);
	ft_div(a, b, 70, 115);
	ft_div(a, b, 45, 70);
	ft_div(a, b, 22, 45);
	ft_div(a, b, 10, 22);
	ft_sort10(a, b);
}
/*	int	i;
	int	y;
	int	z;
	
	i = a->nb_element;
	y = a->nb_element;
	z = a->gps_max;
	while (a->nb_element > 25)
	{
		i = i * 8 / 10;
		y = y * 8 % 10;
		ft_div(a, b, i + y, z);
		z = i + y;
	}
	if (a->nb_element > 10)
		ft_div(a, b, 10, z);*/
