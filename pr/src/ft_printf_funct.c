/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:41:26 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/05 19:51:21 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr_printf(void *nb, t_opt opt)
{
	int	count;

	count = ft_putadr_printf_aff(nb, 0);
	count = ft_putnchar_option(count, opt, 0 == 1);
	ft_putadr_printf_aff(nb, 1);
	count = ft_putnchar_option(count, opt, 1 == 1);
	return (count);
}

int	ft_puthexa_printf(unsigned long long nb, int maj, t_opt opt)
{
	int	count;

	if (opt.fill_char == '0')
	{
		if (opt.size_max == -1)
			opt.size_max = opt.size_min;
	}
	opt.fill_char = ' ';
	count = ft_puthexa_printf_aff(nb, maj, 0, opt.size_max);
	if (opt.prefix && nb != 0)
	{
		if (maj)
			count += ft_putstr_printf_aff("0X", 1, opt.size_max);
		else
			count += ft_putstr_printf_aff("0x", 1, opt.size_max);
	}
	count = ft_putnchar_option(count, opt, 0 == 1);
	ft_puthexa_printf_aff(nb, maj, 1, opt.size_max);
	count = ft_putnchar_option(count, opt, 1 == 1);
	return (count);
}

int	ft_putunsigned_printf(unsigned int nb, t_opt opt)
{
	int	count;

	if (opt.fill_char == '0')
	{
		if (opt.size_max == -1)
			opt.size_max = opt.size_min;
	}
	opt.fill_char = ' ';
	count = ft_putunsigned_printf_aff(nb, 0, opt.size_max, opt);
	count = ft_putnchar_option(count, opt, 0 == 1);
	ft_putunsigned_printf_aff(nb, 1, opt.size_max, opt);
	count = ft_putnchar_option(count, opt, 1 == 1);
	return (count);
}

int	ft_putnbr_printf(int nb, t_opt opt)
{
	int	count;

	if (opt.fill_char == '0')
	{
		if (opt.size_max == -1)
			opt.size_max = opt.size_min - (nb < 0);
	}
	opt.fill_char = ' ';
	count = ft_putnbr_printf_aff(nb, 0, opt.size_max, opt);
	count = ft_putnchar_option(count, opt, 0 == 1);
	ft_putnbr_printf_aff(nb, 1, opt.size_max, opt);
	count = ft_putnchar_option(count, opt, 1 == 1);
	return (count);
}

int	ft_putstr_printf(const char *c, t_opt opt)
{
	int	count;

	count = ft_putstr_printf_aff(c, 0, opt.size_max);
	count = ft_putnchar_option(count, opt, 0 == 1);
	ft_putstr_printf_aff(c, 1, opt.size_max);
	count = ft_putnchar_option(count, opt, 1 == 1);
	return (count);
}
