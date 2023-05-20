/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:28:01 by kaly              #+#    #+#             */
/*   Updated: 2023/05/19 20:13:16 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_display(t_data *data)
{
	char	*nb_movement;

	nb_movement = ft_itoa(data->pl_move);
	data->file = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/tree_green.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file,
		PXL * (data->map_x - 1), 0);
	mlx_destroy_image(data->mlx_ptr, data->file);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->pxl * data->map_x
		- 110, 25, 0xFFFFFF, "Movements : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->pxl * data->map_x
		- 35, 25, 0xFFFFFF, nb_movement);
	free(nb_movement);
}

void	ft_dead(t_data *data, int y, int x)
{
	data->alive = 0;
	data->map[data->pl_y][data->pl_x] = '0';
	data->pl_move++;
	data->file = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/fond2.xpm", &data->pxl, &data->pxl);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file,
		PXL * data->pl_x, PXL * data->pl_y);
	mlx_destroy_image(data->mlx_ptr, data->file);
	data->x = x;
	data->y = y;
	ft_put_ennemy(data);
	ft_printf("Game Over !!!\n");
	ft_quit2(data);
}

int	ft_check_move(t_data *data, char dest, int y, int x)
{
	if (dest == 'E')
	{
		if (data->collect == 0)
		{
			data->exit = 0;
			return (1);
		}
		if (data->collect > 0)
			return (0);
	}
	if (dest == 'C')
	{
		data->collect--;
		ft_printf("There are %d collectibles left to find\n", data->collect);
	}
	if (dest == 'A')
	{
		ft_dead(data, y, x);
	}
	return (1);
}
