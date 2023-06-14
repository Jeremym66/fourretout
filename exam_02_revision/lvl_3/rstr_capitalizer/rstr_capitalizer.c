/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:15:51 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/05 18:31:14 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			ft_putchar(str[i]);
		else if (is_lowercase(str[i]) == 1)
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == '\0')
				ft_putchar(str[i] - 32);
			else
				ft_putchar(str[i]);
		}
		else if (is_uppercase(str[i]) == 1)
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == '\0')
				ft_putchar(str[i]);
			else
				ft_putchar(str[i] + 32);
		}
		else 
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char ** av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		ft_putchar('\n');
		return (1);
	}
	while (i < ac)
	{
		rstr_capitalizer(av[i]);
		i++;
		ft_putchar('\n');
	}
	return (0);
}
