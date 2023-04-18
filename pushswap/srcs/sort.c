/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:51:36 by kaly              #+#    #+#             */
/*   Updated: 2023/04/17 21:12:08 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort(t_pile *a, t_pile *b)
{
	if (ft_check_sort(a) == 1)
	{
//		printf("cest deja trie\n");
		return ;
	}
	else if (a->nb_element == 2 && b->nb_element == 0)
		ft_swap_a(a, 1);
	else if (a->nb_element == 3)
		ft_sort3(a);
	else if (a->nb_element <= 10)
		ft_sort10(a, b);
	else if (a->nb_element <= 100)
		ft_sort100(a, b);
	else
		ft_sort_max(a, b);
}
