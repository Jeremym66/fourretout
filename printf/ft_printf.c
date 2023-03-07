/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 05:10:05 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/07 05:58:45 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.c"

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += ft_detect_param(*(++str), args);
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}

int	ft_detect_param(char conv, va_list args)
{
	unsigned long int	pointer;

	if (conv == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (conv == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (conv == 'd' || conv == 'i')
		return (ft_putnbrbase(va_arg(args, int), "0123456789", conv));
	else if (conv == 'u')
		return (ft_putnbrbase(va_arg(args, unsigned int), "0123456789", conv));
	else if (conv == 'x' || conv == 'X')
		return (ft_putnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF", conv));
	else if (conv == 'p')
	{
		pointer = va_arg(args, unsigned long int)
		if (pointer == 0)
			return (ft_putstr(PTR_NULL));
		write(1, "0x", 2);
		return (ft_putnbrbase(pointer, "0123456789ABCDEF", conv) + 2);
	}
	else
		return(ft_putchar(conv));
	
}

int	ft_putnbrbase(long long int nbr, char *base, char conv)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		count += write(1, '-', 1);
		nbr = -nbr;
	}
	if (nbr < 10)
		count += ft_putchar(nbr + '0');
	else if (nbr < base_len)
	{
		if (conv == 'x' || conv == 'p')
			count += ft_putchar(nbr - 10 + 'a');
		else if(conv == 'X')
			count += ft_putchar(nbr - 10 + 'A');
	}
	else
	{
		count += ft_putnbrbase(nbr / base_len, base, conv);
		count += ft_putnbrbase(nbr % base_len, base, conv);
	}
	return (count);
}
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*coucou;

	coucou = NULL;
	printf("\n(%d)\n\n", printf("%%, %c, %s, %d, %i, %u, %X, %x, %p, %p ", 'c', "coucou", 42, -42, 2147483647, 1658, 1203658, &coucou, coucou));
	return (0);
}
