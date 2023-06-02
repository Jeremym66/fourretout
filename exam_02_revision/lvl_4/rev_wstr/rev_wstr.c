/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:47:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/02 18:08:49 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_wstr(char *str)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
//		printf("i = %d\n", i);
//		printf("j = %d\n", j);
//		printf("k = %d\n", k);
		k = i;
		while (str[i] != ' ' && i > -1)
			i--;
		j = i + 1;
		while (j <= k)
		{
			ft_putchar(str[j]);
			j++;
		}
		if (str[i] == ' ')
			ft_putchar(' ');
		i--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	ft_putchar('\n');
	return (0);
}
