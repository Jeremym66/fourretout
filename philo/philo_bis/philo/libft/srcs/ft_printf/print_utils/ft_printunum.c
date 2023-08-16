/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printunum.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ocartier <ocartier@student.42lyon.f>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/01 14:11:31 by ocartier		  #+#	#+#			 */
/*   Updated: 2021/12/02 16:53:52 by ocartier		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	print_unumber(unsigned long nl)
{
	int				total;
	unsigned long	num;

	total = 0;
	num = nl;
	if (num > 100)
		total += print_unumber(num / 10);
	else if (num == 100)
		total += print_str("10");
	else if ((num / 10) > 0)
		total += print_char((num / 10) + '0');
	total += print_char((num % 10) + '0');
	return (total);
}

static int	number_of_digit(unsigned long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		cur++;
	}
	return (cur);
}

static int	get_values(char	*prefix, int *lp, t_opt *opt, unsigned long num)
{
	int	len;

	len = number_of_digit(num);
	*lp = len;
	if (opt->precision > len)
		*lp = opt->precision;
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

static int	print_u(int len, unsigned long num, t_opt opt)
{
	int	total;

	total = 0;
	if (num == 0 && opt.min_width && opt.min_width < len)
		total += print_char(' ');
	else if (num == 0 && opt.dot && !opt.precision && opt.min_width >= len)
		total += print_char(' ');
	else if (!(num == 0 && opt.dot && !opt.precision))
		total += print_unumber(num);
	return (total);
}

int	pf_printunum(unsigned long num, t_opt opt)
{
	int		total;
	int		len;
	int		len_prec;
	char	prefix;

	total = 0;
	len = get_values(&prefix, &len_prec, &opt, num);
	while (len_prec + total < opt.min_width)
		total += print_char(prefix);
	while (len + total < opt.min_width)
		total += print_char('0');
	total += print_u(len, num, opt);
	while (total < opt.offset)
		total += print_char(' ');
	return (total);
}
