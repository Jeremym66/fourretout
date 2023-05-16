/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:04:51 by kaly              #+#    #+#             */
/*   Updated: 2023/05/16 17:08:13 by kaly             ###   ########.fr       */
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

int	ft_quit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_free_map(data);
	free(data->map);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}

int	ft_path(t_data *data, int y, int x)
{
//	int	i;
	int	check_exit;

	check_exit = 0;
//	i = 0;
	check_exit = y;
	y = x;
	x = check_exit;
	ft_printf("...data->path\n");
               ft_printf("%s\n", data->map[0]);
               ft_printf("%s\n", data->path[0]);
//               ft_printf("%s\n", data->map[0]);
/*         while (data->map[i])
        {
                ft_printf("%s\n", data->map[i]);
                i++;
        }*/
//	       while (data->path[i])
//       {
//                ft_printf("%s\n", data->path[0]);
//                i++;
//        }
/*	if (data->path[y - 1][x] == '0' || data->path[y - 1][x] == 'C')
	{
		data->path[y - 1][x] = 'X';
		ft_path(data, y - 1, x);
	}
	if (data->path[y + 1][x] == '0' || data->path[y + 1][x] == 'C')
        {
                data->path[y + 1][x] = 'X';
                ft_path(data, y + 1, x);
        }
	if (data->path[y][x - 1] == '0' || data->path[y][x - 1] == 'C')
        {
                data->path[y][x - 1] = 'X';
                ft_path(data, y, x - 1);
        }
	if (data->path[y][x + 1] == '0' || data->path[y][x + 1] == 'C')
        {
                data->path[y][x + 1] = 'X';
                ft_path(data, y, x + 1);
        }
	check_exit++;*/
	return (0);
}
