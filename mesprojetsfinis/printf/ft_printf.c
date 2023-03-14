/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 05:10:05 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/14 13:59:32 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_detect_param(char conv, va_list args)
{
	long unsigned int	pointer;

	if (conv == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (conv == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (conv == 'd' || conv == 'i')
		return (ft_printnbr(va_arg(args, long int)));
	else if (conv == 'u')
		return (ft_printnbrbase(va_arg(args, unsigned int),
				"0123456789", conv));
	else if (conv == 'x' || conv == 'X')
		return (ft_printnbrbase(va_arg(args, unsigned int),
				"0123456789ABCDEF", conv));
	else if (conv == 'p')
	{
		pointer = va_arg(args, long unsigned int);
		if (pointer == 0)
			return (ft_printstr(PTR_NULL));
		write(1, "0x", 2);
		return (ft_printnbrhexa(pointer, "0123456789ABCDEF", conv) + 2);
	}
	else
		return (ft_printchar(conv));
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += ft_detect_param(*(++str), args);
		else
			count += ft_printchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
