/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:59:47 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/22 16:43:05 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_wstr(char *str)
{
	int	i;
	int	start;
	int	end;
	int	flag;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		while (str[i] == 0 || str[i] == ' ' || str[i] == '\t')
			i--;
		end = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i--;
		start = i + 1;
		flag = start;
		while (start <= end)
		{
			ft_putchar(str[start]);
			start++;
		}
		if (flag != 0)
			ft_putchar(' ');
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	ft_putchar ('\n');
	return(0);
}
