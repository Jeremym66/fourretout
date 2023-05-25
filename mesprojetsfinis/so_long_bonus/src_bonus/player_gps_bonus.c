/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_gps_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:38:54 by kaly              #+#    #+#             */
/*   Updated: 2023/05/25 15:04:39 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				data->pl_x = i;
				data->pl_y = j;
				return ;
			}
			i++;
		}
		j++;
	}	
}

void	ft_move_up(t_data *data)
{
	if (ft_check_move(data, data->map[data->pl_y - 1][data->pl_x],
		data->pl_y - 1, data->pl_x) == 1)
	{
		data->map[data->pl_y][data->pl_x] = '0';
		data->map[data->pl_y - 1][data->pl_x] = 'P';
		data->pl_move++;
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/fond2.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file,
			PXL * data->pl_x, PXL * data->pl_y);
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/zelda_dos.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
			PXL * data->pl_x, PXL * (data->pl_y - 1));
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->pl_y--;
		ft_printf("Player's moves : %d\n", data->pl_move);
		ft_move_display(data);
	}
}

void	ft_move_down(t_data *data)
{
	if (ft_check_move(data, data->map[data->pl_y + 1][data->pl_x],
		data->pl_y + 1, data->pl_x) == 1)
	{
		data->map[data->pl_y][data->pl_x] = '0';
		data->map[data->pl_y + 1][data->pl_x] = 'P';
		data->pl_move++;
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/fond2.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file,
			PXL * data->pl_x, PXL * data->pl_y);
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/zelda_face.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
			PXL * data->pl_x, PXL * (data->pl_y + 1));
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->pl_y++;
		ft_printf("Player's moves : %d\n", data->pl_move);
		ft_move_display(data);
	}
}

void	ft_move_left(t_data *data)
{
	if (ft_check_move(data, data->map[data->pl_y][data->pl_x - 1],
		data->pl_y, data->pl_x - 1) == 1)
	{
		data->map[data->pl_y][data->pl_x] = '0';
		data->map[data->pl_y][data->pl_x - 1] = 'P';
		data->pl_move++;
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/fond2.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file,
			PXL * data->pl_x, PXL * data->pl_y);
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/zelda_left.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
			PXL * (data->pl_x - 1), PXL * data->pl_y);
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->pl_x--;
		ft_printf("Player's moves : %d\n", data->pl_move);
		ft_move_display(data);
	}
}

void	ft_move_right(t_data *data)
{
	if (ft_check_move(data, data->map[data->pl_y][data->pl_x + 1],
		data->pl_y, data->pl_x + 1) == 1)
	{
		data->map[data->pl_y][data->pl_x] = '0';
		data->map[data->pl_y][data->pl_x + 1] = 'P';
		data->pl_move++;
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/fond2.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file,
			PXL * data->pl_x, PXL * data->pl_y);
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->file = mlx_xpm_file_to_image(data->mlx_ptr,
				"./img/zelda_right.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file,
			PXL * (data->pl_x + 1), PXL * data->pl_y);
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->pl_x++;
		ft_printf("Player's moves : %d\n", data->pl_move);
		ft_move_display(data);
	}
}
