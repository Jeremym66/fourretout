/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:18:06 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 21:25:37 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free(t_pile *pile)
{
	while (pile->base != pile->top)
		ft_unstack(pile);
	ft_unstack(pile);
}

void	ft_unstack(t_pile *pile)
{
	t_elem	*element_unstacked;

	if (pile == NULL)
		return ;
	element_unstacked = pile->top;
	if (pile->top != NULL)
	{
		pile->top = element_unstacked->next;
		pile->nb_element--;
		free(element_unstacked);
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_pile	*ft_init_list(void)
{
	t_pile	*pile;

	pile = malloc(sizeof(*pile));
	if (!pile)
		exit(EXIT_FAILURE);
	pile->top = NULL;
	pile->base = NULL;
	pile->nb_element = 0;
	pile->gps_max = 0;
	return (pile);
}

void	ft_stack(t_pile *pile, long int new_nb)
{
	t_elem	*new;
	t_elem	*base_existing;

	base_existing = pile->base;
	new = malloc(sizeof(*new));
	if (!new || !pile)
		return ;
	new->nb = new_nb;
	new->gps = 1;
	new->next = NULL;
	if (pile->base == NULL)
		pile->top = new;
	else
		base_existing->next = new;
	pile->base = new;
	pile->nb_element++;
}
