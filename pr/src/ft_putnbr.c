/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:02:23 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/05 18:56:54 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recur(unsigned int n, int aff)
{
	int	cpt;

	cpt = 0;
	if (n < 10)
		cpt += ft_putchar_printf_aff((char)(n + '0'), aff);
	else
	{
		cpt += ft_putnbr_recur(n / 10, aff);
		cpt += ft_putchar_printf_aff((char)(n % 10 + '0'), aff);
	}
	return (cpt);
}

static int	ft_putnnbr(unsigned int n, int aff, int c)
{
	int	cpt;

	cpt = 0;
	if (c <= 0 && n == 0)
		return (0);
	if (c <= 1 && n < 10)
		cpt += ft_putchar_printf_aff((char)(n + '0'), aff);
	else
	{
		cpt += ft_putnnbr(n / 10, aff, c - 1);
		cpt += ft_putchar_printf_aff((char)(n % 10 + '0'), aff);
	}
	return (cpt);
}

int	ft_putnbr_printf_aff(int n, int aff, int opt, t_opt optl)
{
	int	cpt;

	cpt = 0;
	if (n >= 0 && optl.is_space)
		cpt += ft_putchar_printf_aff(' ', aff);
	else if (n >= 0 && optl.is_sign)
		cpt += ft_putchar_printf_aff('+', aff);
	if (n < 0)
	{
		cpt += ft_putchar_printf_aff('-', aff);
		n *= -1;
	}
	if (opt <= -1)
		cpt += ft_putnbr_recur((unsigned int) n, aff);
	else
		cpt += ft_putnnbr((unsigned int) n, aff, opt);
	return (cpt);
}
