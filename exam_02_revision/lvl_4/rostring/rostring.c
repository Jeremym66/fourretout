/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:29:59 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/15 14:57:13 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	rostring(char *str)
{
	int	i;
	int	start;
	int	end;
	int	other_words;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	end = i - 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	other_words = 1;
	if (str[i] == 0)
		other_words = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			ft_putchar(' ');
			while (str[i] == ' ' || str[i] == '\t')
				i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	if (other_words == 1)
		ft_putchar(' ');
	i = start;
	while (i <= end)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		rostring(av[1]);
	ft_putchar('\n');
	return (0);
}
