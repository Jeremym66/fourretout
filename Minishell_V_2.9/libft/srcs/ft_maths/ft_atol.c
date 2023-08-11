/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:54:34 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:02:17 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long	ft_atol(const char	*str)
{
	long long	negatif;
	long long	resultat;

	negatif = 0;
	resultat = 0;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			negatif++;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultat = resultat * 10 + (*str - '0');
		str++;
	}
	if ((negatif % 2) == 1)
		return (-resultat);
	else
		return (resultat);
}
