/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:17:51 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/31 17:45:18 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_first(int a)
{
	int	i;

	i = a - 1;
	while (i > 1)
	{
		if (a % i == 0)
			break;
		i--;
	}
	if (i == 1)
		return(1);
	else
		return(0);
}

void	ft_prime(int a)
{
	int	i;

	if (a == 1)
		printf("%d", a);
	i = 2;
	while(i <= a)
	{
		if (a % i == 0)
		{
			if (is_first(a) == 0)
				printf("%d*", i);
			else
				printf("%d", i);
			a /= i;
			i = 2;	
		}
		else
			i++;
	}
	
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_prime(atoi(av[1]));
	printf("\n");
	return(0);
}
