/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:02:23 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/01 11:26:17 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recur_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd((char)(n + '0'), fd);
	else
	{
		ft_putnbr_recur_fd(n / 10, fd);
		ft_putchar_fd((char)(n % 10 + '0'), fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_putnbr_recur_fd((unsigned int) n, fd);
}
