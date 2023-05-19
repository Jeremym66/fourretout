/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:55:15 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/19 19:40:59 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*reverse_malloc(char *s)
{
	char	*str;
	int		end;
	int		i;

	end = ft_strlen(s);
	str = malloc(sizeof(char) * (end + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (--end >= 0)
	{
		str[++i] = s[end];
	}
	str[++i] = 0;
	return (str);
}

static char	*malloc_zero(void)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[1] = 0;
	return (ret);
}

char	*ft_itoa(int n)
{
	char			ret[12];
	int				i;
	int				sign;
	long int		nb;

	if (n == 0)
		return (malloc_zero());
	nb = (long int)n;
	sign = 1;
	if (nb < 0)
	{
		sign *= -1;
		nb = -nb;
	}
	i = 0;
	while (nb)
	{
		ret[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	if (sign == -1)
		ret[i++] = '-';
	ret[i] = 0;
	return (reverse_malloc(ret));
}
