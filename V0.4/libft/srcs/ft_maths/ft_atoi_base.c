/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 06:44:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:02:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_instr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_checkbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || ft_instr(base[i], base + i + 1))
			return (1);
		if ((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_atoi1(char *str, char *base, int len)
{
	int	i;
	int	signe;
	int	res;

	res = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_instr(str[i], base) != -1)
	{
		res = res * len + ft_instr(str[i], base);
		i++;
	}
	return (res * signe);
}

int	ft_atoi_base(char *nb, char *base)
{
	unsigned int	len;

	len = 0;
	while (base[len])
		len++;
	if (ft_checkbase(base) == -1 || len < 2)
		return (0);
	return (ft_atoi1(nb, base, len));
}
