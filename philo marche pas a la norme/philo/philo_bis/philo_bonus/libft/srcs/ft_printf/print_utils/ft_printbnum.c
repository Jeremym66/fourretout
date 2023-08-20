/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:12:32 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 15:10:01 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static int	print_number_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nbrl;
	int				total;

	total = 0;
	nbrl = nbr;
	base_len = pf_strlen(base);
	if (nbrl >= base_len)
	{
		total += print_number_base(nbrl / base_len, base);
		total += print_number_base(nbrl % base_len, base);
	}
	else
	{
		total += print_char(base[nbrl]);
	}
	return (total);
}

static int	get_hex_size(int nbr)
{
	int				total;
	unsigned int	nbrl;

	total = 0;
	nbrl = nbr;
	if (nbrl >= 16)
	{
		total += get_hex_size(nbrl / 16);
		total += get_hex_size(nbrl % 16);
	}
	else
		total++;
	return (total);
}

static int	get_values(char	*prefix, int *len_prec, t_opt *opt, int nbr)
{
	int		len;

	len = get_hex_size(nbr);
	*len_prec = len;
	if (opt->precision > len)
		*len_prec = opt->precision;
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

static int	print_x(int is_maj, int len, int nbr, t_opt opt)
{
	int	total;

	total = 0;
	if (nbr == 0 && opt.min_width && opt.min_width < len)
		total += print_char(' ');
	else if (nbr == 0 && opt.dot && !opt.precision && opt.min_width >= len)
		total += print_char(' ');
	else if (!(nbr == 0 && opt.dot && !opt.precision))
	{
		if (is_maj)
			total += print_number_base(nbr, "0123456789ABCDEF");
		else
			total += print_number_base(nbr, "0123456789abcdef");
	}
	return (total);
}

int	pf_printbnum(int nbr, int is_maj, t_opt opt)
{
	int		total;
	int		len;
	char	prefix;
	int		len_prec;

	total = 0;
	len = get_values(&prefix, &len_prec, &opt, nbr);
	while (len_prec + total < opt.min_width)
		total += print_char(prefix);
	while (len + total < opt.min_width)
		total += print_char('0');
	if (opt.sharp && nbr != 0)
	{
		if (is_maj)
			total += print_str("0X");
		else
			total += print_str("0x");
	}
	total += print_x(is_maj, len, nbr, opt);
	while (total < opt.offset)
		total += print_char(' ');
	return (total);
}
