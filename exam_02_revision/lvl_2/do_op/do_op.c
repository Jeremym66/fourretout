/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:39:43 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/15 16:51:49 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	do_op(int a, int b, char c)
{
	int	res;

	if (c == '+')
		res = a + b;
	if (c == '-')
		res = a - b;
	if (c == '*')
		res = a * b;
	if (c == '/')
		res = a / b;
	if (c == '%')
		res = a % b;
	printf("%d\n", res);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(atoi(av[1]), atoi(av[3]), av[2][0]);
	else
		ft_putchar('\n');
	return (0);
}
