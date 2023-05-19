/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:28:01 by kaly              #+#    #+#             */
/*   Updated: 2023/05/19 15:53:43 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		data->alive = 0;
		data->map[data->pl_y][data->pl_x] = '0';
		                data->pl_move++;
                data->file = mlx_xpm_file_to_image(data->mlx_ptr,
                                "../img/fond2.xpm", &data->pxl, &data->pxl);
                mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file,
                        PXL * data->pl_x, PXL * data->pl_y);
                mlx_destroy_image(data->mlx_ptr, data->file);
		data->x = x;
		data->y = y;
		ft_put_ennemy(data);
	}

	return (1);
}


