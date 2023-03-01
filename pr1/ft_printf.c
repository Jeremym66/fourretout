/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhony <rhony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:49:48 by rhony             #+#    #+#             */
/*   Updated: 2023/02/28 16:14:07 by rhony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_conv(char c)
{
	int			i;
	const char	conv[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};

	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	vl;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	va_start(vl, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (is_conv(s[i + 1]))
				len += is_int(s[i++ + 1], vl);
			else
				len += ft_putchar_fd(s[i++], 1);
		}
		else
			len += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(vl);
	return (len);
}
