/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:18:13 by kaly              #+#    #+#             */
/*   Updated: 2023/09/29 11:02:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->exit = 1;
	data->ya = 0.00;
	data->xa = 0.00;
	data->anglerad = 0.00;
	data->first_x = 0.00;
	data->dist_x = 0.00;
	data->first_y = 0.00;
	data->dist_y = 0.00;
	data->dist = 0.00;
	data->orient = 0.00;
	data->beta = 30.00;
	data->horizon = WINDOW_H / 2;
	data->i = 0;
	data->o = 0;
	data->scale = 60.0000000 / WINDOW_W;
}

void	ft_check(char **argv, t_data *data)
{
	if (ft_create_map(data, argv))
		ft_exit_failure(data, -1, NULL, "DATA : KO");
	else
		titre(" DATA : OK ");
	if (ft_test_map(data))
	{
		titre_err(" MAP :\t\t\033[31mKO\033[0m\n");
		ft_clean_map_and_inside(data);
		ft_quit(data);
	}
	if (ft_test_perso(data))
		ft_exit_failure(data, 3, NULL, \
		"Personnage : 1\t\t\t\033[32mKO\033[0m\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	ft_check_arg(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_check(argv, data);
	init_data(data);
	ft_create_window(data);
	return (0);
}
