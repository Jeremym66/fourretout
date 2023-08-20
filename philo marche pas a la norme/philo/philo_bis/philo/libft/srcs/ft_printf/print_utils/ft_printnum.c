/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:10:53 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 15:10:20 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static int	print_minus(long *nl, int *len, t_opt opt)
{
	print_char('-');
	(*nl) = (*nl) * -1;
	(*len)--;
	if (opt.dot)
		(*len)--;
	return (1);
}

static int	number_of_digit(long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		cur++;
	while (num != 0)
	{
		num = num / 10;
		cur++;
	}
	return (cur);
}

static int	get_values(char	*prefix, int *len_prec, t_opt *opt, long nl)
{
	int		len;

	len = number_of_digit(nl);
	*len_prec = len;
	if (opt->precision > len)
		*len_prec = opt->precision;
	if (nl < 0 && opt->zero_offset > len && opt->precision > len)
		(*len_prec)++;
	if (nl < 0 && opt->dot && opt->precision < opt->zero_offset)
		len++;
	*prefix = '0';
	if (opt->zero && opt->dot && opt->zero_offset > opt->precision)
		*prefix = ' ';
	if (!opt->zero)
		*prefix = ' ';
	if (opt->zero)
		opt->min_width = opt->zero_offset;
	if (opt->precision > opt->min_width)
		opt->min_width = opt->precision;
	return (len);
}

static int	print_di(int len, long nl, t_opt opt)
{
	int	total;

	total = 0;
	if (nl == 0 && opt.min_width && opt.min_width < len)
		total += print_char(' ');
	else if (nl == 0 && opt.dot && !opt.precision && opt.min_width >= len)
		total += print_char(' ');
	else if (!(nl == 0 && opt.dot && !opt.precision))
		total += print_number(nl);
	return (total);
}

int	pf_printnum(long nl, t_opt opt)
{
	int		total;
	int		len;
	char	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &opt, nl);
	while (prefix == ' ' && len_prec + total < opt.min_width)
		total += print_char(' ');
	if (nl < 0)
		total += print_minus(&nl, &len, opt);
	else if (opt.space && nl >= 0 && !opt.plus && !opt.dot)
		total += print_char(' ');
	else if (opt.plus && nl >= 0 && !opt.dot)
		total += print_char('+');
	while (len + total < opt.min_width)
		total += print_char('0');
	total += print_di(len, nl, opt);
	while (total < opt.offset)
		total += print_char(' ');
	return (total);
}
