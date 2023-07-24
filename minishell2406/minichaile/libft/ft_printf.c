/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:56:05 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/23 15:02:53 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	check_conv(char c, va_list ap, int *i, char p)
{
	if (c == 'c')
		return (print_c(va_arg(ap, int)));
	if (c == 's')
		return (print_s(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (print_d(va_arg(ap, int)));
	if (c == 'u' || c == 'x' || c == 'X')
		return (print_x(va_arg(ap, unsigned int), c));
	if (c == '%')
		return (print_c(c));
	if (c == 'p')
		return (print_p(va_arg(ap, unsigned long long), 1));
	else
	{
		*i = *i - 1;
		return (print_c(p));
	}
}

int	ft_printf(const char *str, ...)
{
	int		nbrc;
	int		i;
	va_list	ap;

	i = 0;
	nbrc = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			nbrc = nbrc + check_conv(str[i + 1], ap, &i, str[i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			nbrc++;
		}
		i++;
	}
	va_end(ap);
	return (nbrc);
}
