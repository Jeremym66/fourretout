/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:40:52 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/05 20:10:54 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_printf_aff(unsigned int nb, int aff, int opt, t_opt optl)
{
	int	cpt;

	cpt = 0;
	if (opt == 0 && nb == 0)
		return (0);
	if (nb >= 10 || opt > 1)
	{
		cpt += ft_putnbr_printf_aff((int)(nb / 10), aff, opt - 1, optl);
		cpt += ft_putchar_printf_aff(nb % 10 + 48, aff);
	}
	else
		cpt += ft_putchar_printf_aff(nb % 10 + 48, aff);
	return (cpt);
}

int	ft_putnchar_option(int count, t_opt opt, int expected)
{
	if (expected)
	{
		if (count < opt.size_min && opt.way)
			count += ft_putnchar(opt.size_min - count, opt.fill_char);
	}
	else
	{
		if (count < opt.size_min && !opt.way)
			count += ft_putnchar(opt.size_min - count, opt.fill_char);
	}
	return (count);
}
