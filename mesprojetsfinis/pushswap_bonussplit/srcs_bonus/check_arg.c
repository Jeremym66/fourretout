/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:13 by kaly              #+#    #+#             */
/*   Updated: 2023/04/18 21:26:40 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_comp_arg(t_pile *pile, long int nb)
{
	t_elem	*checked;

	checked = pile->top;
	while (checked != NULL)
	{
		if (checked->nb == nb)
			return (1);
		checked = checked->next;
	}
	return (0);
}

int	ft_is_int(long int nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (1);
	return (0);
}

int	ft_arg_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_arg(t_pile *pile, char *str)
{
	if (ft_arg_is_digit(str) == 0 || ft_is_int(ft_atoi(str)) == 0)
	{
		ft_free(pile);
		ft_error();
	}
	if (ft_comp_arg(pile, ft_atoi(str)) == 1)
	{
		ft_free(pile);
		ft_error();
	}
	return (1);
}
