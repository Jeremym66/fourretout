/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:18:13 by kaly              #+#    #+#             */
/*   Updated: 2023/05/10 18:54:29 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->pxl = 50;
	data->map_x = 0;
	data->map_y = 0;
	data->x = 0;
	data->y = 0;
	data->pl_move = 0;
	data->pl_x = 0;
	data->pl_y = 0;
	data->player = 0;
	data->collect = 0;
	data->exit = 0;
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
	printf("There are %d collectibles left to find\n", data->collect);
	ft_create_window(data);
	ft_free_map(data);
	free(data->map);
	free(data->mlx_ptr);
	free(data);
	return (0);
}
