/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 06:02:02 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/29 07:32:22 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_printstr(char * args, int *count)
{
	int	i;

	i = 0;
	if (!args)
		args = "(null)";
	while (args[i])
	{
		*count += ft_printchar(args[i]);
		i++;
	}
}

void	ft_printnbrbase(long long int nbr, int base, int *count)
{
	char	*hexa = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		*count += ft_printchar('-');
	}
	if (nbr >= base)
		ft_printnbrbase(nbr / base, base, count);
	*count += ft_printchar(hexa[nbr % base]);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	count;
	int	i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ((str[i + 1] == 's') || (str[i + 1] == 'd') || (str[i + 1] == 'x')))
		{
			if (str[i + 1] == 's')
				ft_printstr(va_arg(args, char *), &count);
			if (str[i + 1] == 'd')
				ft_printnbrbase(va_arg(args, int), 10, &count);
			if (str[i + 1] == 'x')
				ft_printnbrbase(va_arg(args, unsigned int), 16, &count);
			i++;
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return(count);
}
/*
int	main()
{
	int	count;

	count = 0;
	count = ft_printf("Magic %s is %d\n", "number", -423);
	printf("count ft_printf = %d\n", count);
	count = printf("Magic %s is %d\n", "number", -423);
	printf("count printf = %d\n", count);
	count = ft_printf("coucou\n");
	printf("count ft_printf = %d\n", count);
	count = printf("coucou\n");
	printf("count printf = %d\n", count);
	count = ft_printf("Hexadecimal for %d is %x\n", 42, 886);
	printf("count ft_printf = %d\n", count);
	count = printf("Hexadecimal for %d is %x\n", 42, 886);
	printf("count printf = %d\n", count);
}*/
