/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhony <rhony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:56:24 by rhony             #+#    #+#             */
/*   Updated: 2023/02/28 15:56:09 by rhony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_unsigned(char c, va_list vl)
{
	int				len;
	char			*res;
	unsigned int	n;

	if (c == 'u')
	{
		res = ft_uitoa(va_arg(vl, unsigned int));
		ft_putstr_fd(res, 1);
		len = ft_strlen(res);
		free(res);
		return (len);
	}
	return (is_hex(c, vl));
}

int	is_hex(char c, va_list vl)
{
	int				len;
	int				maj;
	unsigned int	n;

	if (c == 'x' || c == 'X')
	{
		len = 0;
		maj = 0;
		if (c == 'X')
			maj = 1;
		convert_hex(va_arg(vl, unsigned int), maj, &len);
		return (len);
	}
	return (0);
}

void	convert_hex(uintptr_t i, int maj, int *len)
{
	char	res;
	char	*hex_table;

	hex_table = "0123456789abcdef";
	if (i >= 16)
	{
		convert_hex(i / 16, maj, len);
		if (maj && i % 16 > 9)
			ft_putchar_fd(hex_table[i % 16] - 32, 1);
		else
			ft_putchar_fd(hex_table[i % 16], 1);
		(*len)++;
	}
	else
	{
		if (maj && i % 16 > 9)
			ft_putchar_fd(hex_table[i % 16] - 32, 1);
		else
			ft_putchar_fd(hex_table[i % 16], 1);
		(*len)++;
	}
}

int	get_ulen(unsigned int n)
{
	int	len;

	len = 0;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	int		len;
	char	*uint;

	len = get_ulen(n);
	uint = (char *)malloc(sizeof(char) * (len + 1));
	if (!uint)
		return (NULL);
	i = 0;
	uint[len] = '\0';
	len--;
	while (len >= 0)
	{
		uint[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (uint);
}
