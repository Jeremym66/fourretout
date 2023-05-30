/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:11:07 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:40 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int	len;
	int	n;
	char	*result;

	len = 0;
	if (nbr <= 0)
		len++;
	n = nbr;
	while (n)
	{
		len++;
		n = n / 10;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10; 
	}
	return (result);
}
