/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:18:13 by kaly              #+#    #+#             */
/*   Updated: 2023/05/19 19:41:32 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_data(t_data *data)
{
	data->map_x = 0;
	data->map_y = 0;
	data->pxl = 50;
	data->x = 0;
	data->y = 0;
	data->pl_move = 0;
	data->pl_x = 0;
	data->pl_y = 0;
	data->player = 0;
	data->check_collect = 0;
	data->collect = 0;
	data->check_exit = 0;
	data->exit = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->exit_is_open = 0;
	data->alive = 1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	ft_check_arg(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		return (MLX_ERROR);
	init_data(data);
	ft_check_map(argv, data);
	ft_printf("There are %d collectibles left to find\n", data->collect);
	ft_printf("Player's moves : %d\n", data->pl_move);
	ft_create_window(data);
	ft_quit(data);
	return (0);
}
