/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:44:54 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 15:10:46 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	process_normal(const char *str, va_list *params, t_opt opt)
{
	int	total;

	total = 0;
	if (str[1] == 'c')
		total += pf_printchar(va_arg(*params, int), opt);
	else if (str[1] == 's')
		total += pf_printstr(va_arg(*params, char *), opt);
	else if (str[1] == 'p')
		total += pf_printpointer(va_arg(*params, void *), opt);
	else if (str[1] == 'd' || str[1] == 'i')
		total += pf_printnum(va_arg(*params, int), opt);
	else if (str[1] == 'u')
		total += pf_printunum(va_arg(*params, unsigned int), opt);
	else if (str[1] == 'x')
		total += pf_printbnum(va_arg(*params, int), 0, opt);
	else if (str[1] == 'X')
		total += pf_printbnum(va_arg(*params, int), 1, opt);
	else if (str[1] == '%')
		total += print_char('%');
	return (total);
}

void	process_flags(t_opt *opt, const char *str, int *cur)
{
	if (str[1] == '#')
		opt->sharp = 1;
	else if (str[1] == ' ')
		opt->space = 1;
	else if (str[1] == '+')
		opt->plus = 1;
	else if (str[1] == '0')
	{
		opt->zero_offset = pf_atoi(str + 2, cur);
		opt->zero = 1;
	}
	else if (str[1] == '-')
	{
		opt->offset = pf_atoi(str + 2, cur);
		opt->minus = 1;
	}
	else if (str[1] == '.')
	{
		opt->precision = pf_atoi(str + 2, cur);
		opt->dot = 1;
	}
}

int	process(const char *str, va_list *params, int *cur)
{
	int		total;
	t_opt	opt;

	total = 0;
	init_opt(&opt);
	while (in_set(str[(*cur) + 1], "0123456789# +-."))
	{
		if (in_set(str[(*cur) + 1], "# +0-."))
			process_flags(&opt, str + (*cur), cur);
		else
		{
			opt.min_width = pf_atoi(str + (*cur) + 1, cur);
			(*cur)--;
		}
		(*cur)++;
	}
	total += process_normal(str + (*cur), params, opt);
	(*cur)++;
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		cur;
	int		total;

	cur = 0;
	total = 0;
	va_start(params, str);
	while (str[cur])
	{
		if (str[cur] == '%')
			total += process(str, &params, &cur);
		else
			total += print_char(str[cur]);
		cur++;
	}
	va_end(params);
	return (total);
}
