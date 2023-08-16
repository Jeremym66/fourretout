/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:58:41 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 15:10:15 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	pf_printchar(char c, t_opt opt)
{
	int	cur;

	cur = 0;
	while (cur + 1 < opt.min_width)
		cur += print_char(' ');
	cur += print_char(c);
	while (cur < opt.offset)
		cur += print_char(' ');
	return (cur);
}
