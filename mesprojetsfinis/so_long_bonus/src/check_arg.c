/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:04:51 by kaly              #+#    #+#             */
/*   Updated: 2023/05/20 17:49:17 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_comp_ber(char *arg, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
		i++;
	j = 0;
	while (str[j])
		j++;
	i -= j;
	j = 0;
	while (arg[i])
	{
		if (arg[i] != str[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nThe commmand must be : ./so_long <map.ber>\n");
		exit (EXIT_FAILURE);
	}
	if (ft_comp_ber(argv[1], ".ber") == 1)
	{
		ft_printf("Error\nThe map is not a \".ber\" map\n");
		exit (EXIT_FAILURE);
	}
}

void	check_c_e(t_data *data, int y, int x)
{
	if (data->p[y][x] == 'C')
	{
		data->check_collect++;
		data->p[y][x] = 'X';
	}
	if (data->p[y][x] == '0')
		data->p[y][x] = 'X';
	if (data->p[y][x] == 'E')
	{
		data->check_exit++;
		data->p[y][x] = '1';
	}
}

void	ft_path(t_data *d, int y, int x)
{
	if (d->p[y - 1][x] == '0' || d->p[y - 1][x] == 'C' || d->p[y - 1][x] == 'E')
	{
		check_c_e(d, y - 1, x);
		if (d->p[y - 1][x] != '1')
			ft_path(d, y - 1, x);
	}
	if (d->p[y + 1][x] == '0' || d->p[y + 1][x] == 'C' || d->p[y + 1][x] == 'E')
	{
		check_c_e(d, y + 1, x);
		if (d->p[y + 1][x] != '1')
			ft_path(d, y + 1, x);
	}
	if (d->p[y][x - 1] == '0' || d->p[y][x - 1] == 'C' || d->p[y][x - 1] == 'E')
	{
		check_c_e(d, y, x - 1);
		if (d->p[y][x - 1] != '1')
			ft_path(d, y, x - 1);
	}
	if (d->p[y][x + 1] == '0' || d->p[y][x + 1] == 'C' || d->p[y][x + 1] == 'E')
	{
		check_c_e(d, y, x + 1);
		if (d->p[y][x + 1] != '1')
			ft_path(d, y, x + 1);
	}
}
