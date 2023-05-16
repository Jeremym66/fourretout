/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:04:51 by kaly              #+#    #+#             */
/*   Updated: 2023/05/12 17:31:37 by kaly             ###   ########.fr       */
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
