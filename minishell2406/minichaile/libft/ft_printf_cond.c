/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cond.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:51:11 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/23 15:00:07 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_d(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	if (n > 9)
	{
		i = i + print_d(n / 10);
		i = i + print_c((n % 10) + '0');
	}
	else
		i = i + print_c(n + '0');
	return (i);
}

int	print_x(unsigned int n, char c)
{
	unsigned int	i;
	unsigned int	t;
	char			*base;

	i = 0;
	t = 16;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
	{
		base = "0123456789";
		t = 10;
	}
	if (n > t - 1)
	{
		i = i + print_x((n / t), c);
		i = i + print_x((n % t), c);
	}
	else
		i = i + write(1, &base[n], 1);
	return (i);
}

int	print_p(unsigned long long n, int d)
{
	unsigned int	i;
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	if (!n && d)
		return (write(1, "(nil)", 5));
	if (d)
		i = i + write(1, "0x", 2);
	if (n > 15)
	{
		i = i + print_p((n / 16), 0);
		i = i + print_p((n % 16), 0);
	}
	else
		i = i + write(1, &base[n], 1);
	return (i);
}
