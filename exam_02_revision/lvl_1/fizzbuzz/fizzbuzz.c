/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:55:07 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/31 16:17:00 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	if (i > 9)
	{
		ft_putnbr(i / 10);
		i %= 10;
	}
	ft_putchar(i + 48);
}

int	main(int ac, char **av)
{
	int	i;

	(void)av;
	if (ac == 1)
	{
		i = 1;
		while(i <= 100)
		{
			if (i % 3 == 0 && i % 5 == 0)
				write(1, "fizzbuzz", 8);
			else if (i % 3 == 0)
				write(1, "fizz", 4);
			else if (i % 5 == 0)
				write(1, "buzz", 4);
			else
				ft_putnbr(i);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
