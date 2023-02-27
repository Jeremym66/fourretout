/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:34:10 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/04 18:47:10 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_printf_aff(unsigned long long nb, int maj, int aff, int c)
{
	char	*hex;
	int		cpt;

	cpt = 0;
	if (c == 0 && nb == 0)
		return (0);
	if (maj == 0)
		hex = HEXA;
	else
		hex = HEXA_MAJ;
	if (nb >= 16 || c > 1)
	{
		cpt += ft_puthexa_printf_aff(nb / 16, maj, aff, c - 1);
		cpt += ft_putchar_printf_aff(hex[nb % 16], aff);
	}
	else
		cpt += ft_putchar_printf_aff(hex[nb % 16], aff);
	return (cpt);
}

int	ft_putadr_printf_aff(void *adr, int aff)
{
	int	cpt;

	cpt = 0;
	if (!adr)
		cpt += ft_putstr_printf_aff("(nil)", aff, 5);
	else
	{
		cpt += ft_putstr_printf_aff("0x", aff, 4);
		cpt += ft_puthexa_printf_aff((unsigned long long)adr, 0, aff, -1);
	}
	return (cpt);
}
