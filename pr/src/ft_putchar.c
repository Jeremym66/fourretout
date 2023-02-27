/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:39:03 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/05 19:03:30 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf_aff(char c, int aff)
{
	if (aff)
		write(1, &c, 1);
	return (1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_putchar_printf(char c, t_opt opt)
{
	int	count;

	count = ft_putchar_printf_aff(c, 0);
	if (opt.is_space)
		count += ft_putchar_printf_aff(' ', 1);
	count = ft_putnchar_option(count, opt, 0 == 1);
	ft_putchar_printf_aff(c, 1);
	count = ft_putnchar_option(count, opt, 1 == 1);
	return (count);
}

int	ft_putnchar(int n, char c)
{
	int	i;

	i = n;
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
	return (i);
}
