/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:42:35 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/31 14:26:37 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_pgcd(int a, int b)
{
	int	i;

	if (a > b)
		i = b;
	else
		i = a;
	while(1)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("%d\n", i);
			return ;
		}
		i--;
	}

}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("\n");
		return (1);
	}
	ft_pgcd(atoi(av[1]), atoi(av[2]));
	return (0);
}
