/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:54:47 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/15 17:39:45 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nb;
	int	i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			sign = -sign;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (sign * nb);
}

int	is_prime(int nb)
{
	int	i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	add_prime_sum(int nb)
{
	int	res;
	int	i;

	i = 2;
	res = 0;
	while (i <= nb)
	{
		if (is_prime(i) == 1)
			res += i;
		i++;
	}
	ft_putnbr(res);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_atoi(av[1]) >= 0)
			add_prime_sum(ft_atoi(av[1]));
		else
			ft_putnbr(0);
	}
	else
		ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}
