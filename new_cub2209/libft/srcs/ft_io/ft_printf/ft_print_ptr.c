/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:28:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/11 16:55:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void	ft_print_adr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_adr(n / 16);
		ft_print_adr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else if (n >= 10)
			ft_print_c((n - 10) + 'a');
	}
}

int	ft_print_p(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_print_s("(nil)");
		return (count);
	}
	count += ft_print_s("0x");
	ft_print_adr(n);
	count += ft_ptr_len(n);
	return (count);
}

int	ft_print_ptr(unsigned long int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == 0)
		flags.width -= ft_strlen("(nil)");
	else
		flags.width -= 2;
	if (flags.left == 1)
		count += ft_print_p(n);
	count += ft_pad_width(flags.width, ft_ptr_len(n), 0);
	if (flags.left == 0)
		count += ft_print_p(n);
	return (count);
}
