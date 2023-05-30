/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_remplace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:42:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/30 15:07:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	char	a;
	char	b;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (ft_strlen(argv[2]) != 1 || ft_strlen(argv[3]) != 1)
	{
		write(1, "\n", 1);
		return (1);	
	}
	i = 0;
	a = argv[2][0];
	b = argv[3][0];
	while (argv[1][i])
	{
		if (argv[1][i] == a)
			write(1, &b, 1);
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
