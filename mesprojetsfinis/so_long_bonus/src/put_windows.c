/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:48:16 by kaly              #+#    #+#             */
/*   Updated: 2023/05/19 20:10:25 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_limits(t_data *data)
{
	data->file = mlx_xpm_file_to_image(data->mlx_ptr, "./img/tree_green.xpm",
			&data->pxl, &data->pxl);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
		PXL * data->x, PXL * data->y);
	mlx_destroy_image(data->mlx_ptr, data->file);
}

void	ft_put_collect(t_data *data)
{
	data->file = mlx_xpm_file_to_image(data->mlx_ptr, "./img/diamond.xpm",
			&data->pxl, &data->pxl);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
		PXL * data->x, PXL * data->y);
	mlx_destroy_image(data->mlx_ptr, data->file);
}

void	ft_put_player(t_data *data)
{
	data->file = mlx_xpm_file_to_image(data->mlx_ptr, "./img/zelda_face.xpm",
			&data->pxl, &data->pxl);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
		PXL * data->x, PXL * data->y);
	mlx_destroy_image(data->mlx_ptr, data->file);
}

void	ft_put_exit(t_data *data)
{
	if (data->collect == 0)
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/house_open.xpm", &data->pxl, &data->pxl);
	else
	{
		data->exit_x = data->x;
		data->exit_y = data->y;
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/house_close.xpm", &data->pxl, &data->pxl);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
		PXL * data->x, PXL * data->y);
	mlx_destroy_image(data->mlx_ptr, data->file);
}
