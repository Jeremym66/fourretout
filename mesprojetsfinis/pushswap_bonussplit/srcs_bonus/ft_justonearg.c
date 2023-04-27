/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justonearg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 23:42:17 by kaly              #+#    #+#             */
/*   Updated: 2023/04/28 00:13:17 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}

void	ft_justonearg(t_pile *a, char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (argv[i])
		{
			if (ft_check_arg(a, argv[i]) == 1)
				ft_stack(a, ft_atoi(argv[i]));
			i++;
		}
		ft_free_split(argv);
		free(argv);
	}
	else
		while (++i < argc)
			if (ft_check_arg(a, argv[i]) == 1)
				ft_stack(a, ft_atoi(argv[i]));
}
