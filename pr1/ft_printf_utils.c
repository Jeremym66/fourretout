/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhony <rhony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:17:24 by rhony             #+#    #+#             */
/*   Updated: 2023/02/28 16:17:26 by rhony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_int(char c, va_list vl)
{
	int		len;
	int		val;
	char	*num;

	if (c == 'd' || c == 'i')
	{
		val = va_arg(vl, int);
		ft_putnbr_fd(val, 1);
		num = ft_itoa(val);
		len = ft_strlen(num);
		free(num);
		return (len);
	}
	return (is_char(c, vl));
}

int	is_char(char c, va_list vl)
{
	int	val;

	if (c == 'c')
	{
		val = va_arg(vl, int);
		ft_putchar_fd(val, 1);
		return (1);
	}
	return (is_string(c, vl));
}

int	is_string(char c, va_list vl)
{
	char	*val;

	if (c == 's')
	{
		val = va_arg(vl, char *);
		if (!val)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(val, 1);
		return (ft_strlen(val));
	}
	return (is_pointer(c, vl));
}

int	is_pointer(char c, va_list vl)
{
	int			len;
	uintptr_t	val;

	if (c == 'p')
	{
		len = 2;
		val = (uintptr_t)va_arg(vl, void *);
		if (!val)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		convert_hex(val, 0, &len);
		return (len);
	}
	return (is_unsigned(c, vl));
}
