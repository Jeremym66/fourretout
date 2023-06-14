/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:57:45 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/06 15:10:27 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	repeat_alpha(char *str)
{
	int	i;
	int	alpha;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			alpha = str[i] - 'a';
			while (alpha >= 0)
			{
				ft_putchar(str[i]);
				alpha--;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			alpha = str[i] - 'A';
			while (alpha >= 0)
			{
				ft_putchar(str[i]);
				alpha--;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	ft_putchar('\n');
	return (0);
}
