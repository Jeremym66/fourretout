/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:27:57 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/01 11:06:27 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizeint(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_charcat(char *str, char c)
{
	size_t	i;

	i = ft_strlen(str);
	str[i] = c;
	str[i + 1] = '\0';
}

static void	ft_itoa_recurs(char *str, unsigned int n)
{
	if (n < 10)
		ft_charcat(str, (char)(n + '0'));
	else
	{
		ft_itoa_recurs(str, n / 10);
		ft_charcat(str, (char)(n % 10 + '0'));
	}
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)ft_calloc(ft_sizeint(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		ft_charcat(str, '-');
		n *= -1;
	}
	ft_itoa_recurs(str, (unsigned int) n);
	return (str);
}
