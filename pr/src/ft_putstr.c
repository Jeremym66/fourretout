/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:40:04 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/05 11:37:46 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf_aff(char const *str, int aff, int size)
{
	size_t	len;

	if (!str)
	{
		len = 0;
		if (size == -1 || size >= 6)
			len = 6;
		if (aff)
			write(1, "(null)", len);
	}
	else
	{
		len = ft_strlen(str);
		if (size != -1)
			len = ft_min(len, size);
		if (aff)
			write(1, str, len);
	}
	return (len);
}
