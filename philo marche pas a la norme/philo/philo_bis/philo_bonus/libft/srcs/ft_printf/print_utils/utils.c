/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:17:29 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 15:10:37 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

void	init_opt(t_opt *opt)
{
	opt->sharp = 0;
	opt->space = 0;
	opt->plus = 0;
	opt->minus = 0;
	opt->min_width = 0;
	opt->dot = 0;
	opt->precision = 0;
	opt->zero = 0;
	opt->zero_offset = 0;
	opt->offset = 0;
}

int	pf_strlen(char *str)
{
	int	cur;

	cur = 0;
	if (!str)
		return (cur);
	while (str[cur])
		cur++;
	return (cur);
}

int	pf_atoi(const char *str, int *o_cur)
{
	int	cur;
	int	num;

	cur = 0;
	num = 0;
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		num = num * 10 + str[cur] - '0';
		cur++;
		(*o_cur)++;
	}
	return (num);
}

int	in_set(char c, char *set)
{
	int	cur;

	cur = -1;
	while (set[++cur])
		if (set[cur] == c)
			return (1);
	return (0);
}

int	print_number(long nl)
{
	int		total;
	long	num;

	total = 0;
	num = nl;
	if (nl < 0)
	{
		total += print_char('-');
		num = -nl;
	}
	if (num > 100)
		total += print_number(num / 10);
	else if (num == 100)
		total += print_str("10");
	else if ((num / 10) > 0)
		total += print_char((num / 10) + '0');
	total += print_char((num % 10) + '0');
	return (total);
}
