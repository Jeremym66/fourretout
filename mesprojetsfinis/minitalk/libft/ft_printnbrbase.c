/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:48:13 by jmetezea          #+#    #+#             */
/*   Updated: 2023/04/01 18:07:54 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbrbase(long int nbr, char *base, char conv)
{
	int	count;

	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < 10)
		count += ft_printchar(nbr + '0');
	else if (nbr < ft_strlen_printf(base))
	{
		if (conv == 'x')
			count += ft_printchar(nbr - 10 + 'a');
		else if (conv == 'X')
			count += ft_printchar(nbr - 10 + 'A');
	}
	else
	{
		count += ft_printnbrbase(nbr / ft_strlen_printf(base), base, conv);
		count += ft_printnbrbase(nbr % ft_strlen_printf(base), base, conv);
	}
	return (count);
}
