/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:56:18 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 20:29:56 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_sort(t_pile *a, t_pile *b)
{
	t_elem	*check_a;
	t_elem	*check_b;
	int		i;

	check_a = a->top;
	check_b = b->top;
	i = 1;
	if (check_b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (check_a != NULL)
	{
		if (check_a->gps != i)
		{
			write(1, "KO\n", 3);
			return ;
		}
		i++;
		check_a = check_a->next;
	}		
	write(1, "OK\n", 3);
}
