/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:04:51 by kaly              #+#    #+#             */
/*   Updated: 2023/05/16 20:42:00 by jmetezea         ###   ########.fr       */
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
	if (data->path[y][x] == 'C')
		data->check_collect++;
	if (data->path[y][x] == 'E')
		data->check_exit++;
	data->path[y][x] = 'X';
}

void	ft_path(t_data *data, int y, int x)
{
	if (data->path[y - 1][x] == '0' || data->path[y - 1][x] == 'C'
		|| data->path[y - 1][x] == 'E')
	{
		check_c_e(data, y - 1, x);
		ft_path(data, y - 1, x);
	}
	if (data->path[y + 1][x] == '0' || data->path[y + 1][x] == 'C'
		|| data->path[y + 1][x] == 'E')
	{
		check_c_e(data, y + 1, x);
		ft_path(data, y + 1, x);
	}
	if (data->path[y][x - 1] == '0' || data->path[y][x - 1] == 'C'
		|| data->path[y][x - 1] == 'E')
	{
		check_c_e(data, y, x - 1);
		ft_path(data, y, x - 1);
	}
	if (data->path[y][x + 1] == '0' || data->path[y][x + 1] == 'C'
		|| data->path[y][x + 1] == 'E')
	{
		check_c_e(data, y, x + 1);
		ft_path(data, y, x + 1);
	}
}
