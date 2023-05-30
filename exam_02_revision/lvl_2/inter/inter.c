/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:23:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/30 15:47:25 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_doble(char *str, int i)
{
	int	j;

	j = 0;
	while (j != i)
	{
		if (str[j] == str[i])
			return (1);
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j] && ft_doble(argv[1], i) == 0)
			{
				write(1, &argv[1][i], 1);
				break ;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}
