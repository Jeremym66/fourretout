/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:22:30 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:43:36 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_sign(int *n)
{
	if (*n < 0)
	{
		(*n) *= -1;
		return (-1);
	}
	else
		return (1);
}

int	get_len(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*alloc_sign_based(int s, int *l)
{
	char	*r;

	if (s >= 0)
		(*l) += 1;
	else
		(*l) += 2;
	r = (char *)malloc(sizeof(char) * (*l));
	if (r == NULL && (*l) > 0)
		return (0);
	r[*l - 1] = '\0';
	(*l)--;
	return (r);
}

int	check_int_min(int *n)
{
	int	min;

	min = 0;
	if (*n < -2147483647)
	{
		min++;
		(*n)++;
	}
	return (min);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;
	int		min;

	min = check_int_min(&n);
	sign = 1 * get_sign(&n);
	len = get_len(n);
	result = alloc_sign_based(sign, &len);
	if (result == NULL && len > 0)
		return (0);
	while (n >= 10)
	{
		if (min-- > 0)
			result[--len] = (n % 10) + '0' + 1;
		else
			result[--len] = (n % 10) + '0';
		n /= 10;
	}
	result[--len] = n + '0';
	if (sign < 0)
		result[--len] = '-';
	return (result);
}
