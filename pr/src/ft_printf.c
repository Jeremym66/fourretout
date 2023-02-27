/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:23 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/05 20:10:33 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_define(t_opt *opt, int *i, const char *s)
{
	opt->size_max = -1;
	opt->fill_char = ' ';
	opt->way = 0;
	opt->is_zero = 0;
	opt->prefix = 0;
	opt->size_min = 0;
	opt->is_sign = 0;
	opt->is_space = 0;
	while (s[*i] == ' ')
		opt->is_space = (*i)++;
}

t_opt	ft_option_printf(const char *s, int *i)
{
	t_opt	opt;

	ft_define(&opt, i, s);
	while (s[*i] == '+')
		opt.is_sign = (*i)++;
	while (s[*i] == '#')
		opt.prefix = ++(*i);
	while (s[*i] == '0')
		opt.is_zero = ++(*i);
	while (s[*i] == '-')
		opt.way = ++(*i);
	while (s[*i] == '0')
		opt.is_zero = ++(*i);
	opt.size_min = ft_atoi_printf(s, i);
	if (s[*i] == '.')
	{
		(*i)++;
		opt.size_max = ft_atoi_printf(s, i);
	}
	if (opt.is_zero && !opt.way)
		opt.fill_char = '0';
	return (opt);
}

int	ft_printf2(const char *s, va_list ap, int *i)
{
	t_opt	opt;
	int		count;

	if (!s[*i])
		return (-1);
	count = -1;
	opt = ft_option_printf(s, i);
	if (s[*i] == '%')
		count = ft_putchar_printf('%', opt);
	else if (s[*i] == 'i' || s[*i] == 'd')
		count = ft_putnbr_printf((int)va_arg(ap, int), opt);
	else if (s[*i] == 's')
		count = ft_putstr_printf((const char *)va_arg(ap, const char *), opt);
	else if (s[*i] == 'c')
		count = ft_putchar_printf((char)va_arg(ap, int), opt);
	else if (s[*i] == 'u')
		count = ft_putunsigned_printf((unsigned int)va_arg(ap, unsigned int),
				opt);
	else if (s[*i] == 'X' || s[*i] == 'x')
		count = ft_puthexa_printf((unsigned long long)va_arg(ap, unsigned int),
				s[*i] == 'X', opt);
	else if (s[*i] == 'p')
		count = ft_putadr_printf((void *)va_arg(ap, void *), opt);
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		count;
	int		temp;
	int		i;

	count = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			temp = ft_printf2(str, list, &i);
			if (temp == -1)
				break ;
			count += temp;
		}
		else
			count += ft_putchar_printf_aff(str[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}
