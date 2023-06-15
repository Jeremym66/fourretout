/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:45:21 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/15 14:24:40 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	hidenp(char *s1, char *s2)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	j = 0;
	find = 1;
	while (s1[i] && find == 1)
	{
		find = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				find = 1;
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (find == 1)
		ft_putchar('1');
	else
		ft_putchar('0');
}

int	main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
