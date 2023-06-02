/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:57:42 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/02 16:18:17 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	fprime(int n)
{
	int	i;

	i = 2;
	if (n <= 0)
		return ;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	while (i < n)
	{
		if (n % i == 0)
		{
			n /= i;
			printf("%d*", i);
			i--;
		}
		i++;
	}
	printf("%d", i);
	

}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
