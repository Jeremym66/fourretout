/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:00:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/22 12:25:27 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_titre(int i, int j, char *str)
{
	if (i < 16)
	{
		i = (16 - ft_strlen(str)) / 2;
		j = -1;
		while (++j < i)
			ft_printf(" ");
		ft_printf("%s", str);
		j = -1;
		while (++j < i)
			ft_printf(" ");
	}
	else if (i > 16)
	{
		j = -1;
		while (++j < 15)
			ft_printf("%c", str[j]);
		ft_printf(".");
	}
	else
		ft_printf("%s", str);
}

void	titre(char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (!str)
		return ;
	line(1);
	print_titre(i, j, str);
	line(2);
}

int	titre_err(char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (!str)
		return (1);
	line(3);
	print_titre(i, j, str);
	line(2);
	return (1);
}

void	line_up(int i)
{
	int	j;

	j = -1;
	ft_printf("\t***");
	while (++j < i)
		ft_printf("*");
	ft_printf("***\n");
}

void	line(int i)
{
	if (i == 0)
		ft_printf("\t************************\n");
	else if (i == 1)
	{
		ft_printf("\033[34m\t************************\n");
		ft_printf("\t*** ");
	}
	else if (i == 2)
	{
		ft_printf(" ***\n");
		ft_printf("\t************************\n\033[0m");
		ft_printf("\n");
	}
	else if (i == 3)
	{
		ft_printf("\n");
		ft_printf("\033[31m\t************************\n");
		ft_printf("\t*** ");
	}
}
