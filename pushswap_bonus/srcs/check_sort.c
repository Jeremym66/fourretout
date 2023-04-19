/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:56:18 by kaly              #+#    #+#             */
/*   Updated: 2023/04/17 19:32:34 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_check_sort(t_pile *a)
{
	t_elem	*check;
	int		i;

	check = a->top;
	i = 1;
	while (check != NULL)
	{
		if (check->gps != i)
			return (0);
		i++;
		check = check->next;
	}
	return (1);
}
