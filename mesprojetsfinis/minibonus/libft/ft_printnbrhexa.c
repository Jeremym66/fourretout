/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrhexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:34:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/04/01 18:08:17 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbrhexa(long unsigned int nbr, char *base, char conv)
{
	int	count;

	count = 0;
	if (nbr < 10)
		count += ft_printchar(nbr + '0');
	else if (nbr < 16)
		count += ft_printchar(nbr - 10 + 'a');
	else
	{
		count += ft_printnbrhexa(nbr / 16, base, conv);
		count += ft_printnbrhexa(nbr % 16, base, conv);
	}
	return (count);
}
