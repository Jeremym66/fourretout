/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:14:02 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/09 13:26:58 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	taille(int n)
{
	int	r;

	r = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		r = 2;
	}
	while (n >= 10)
	{
		n = n / 10;
		r++;
	}
	return (r);
}

static void	rempli(int n, char *res, int pos)
{
	if (n > 9)
	{
		rempli(n / 10, res, pos - 1);
		res[pos] = (n % 10) + '0';
	}
	else
		res[pos] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		t;

	t = taille(n);
	res = malloc((t + 1) * sizeof (char));
	if (!res)
		return (NULL);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	rempli(n, res, t - 1);
	res[t] = 0;
	return (res);
}
