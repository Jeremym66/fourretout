/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_check_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/29 10:50:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_wall_sw(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->pl_y - (int)(data->first_xa
						+ data->xa * data->i + 1.00)) / PXL;
			data->check_x = (data->pl_x / PXL) + (1 + data->i);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->pl_x + (int)(data->first_ya
						+ data->ya * data->o)) / PXL;
			data->check_y = (data->pl_y / PXL) - (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_se(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->pl_y + (int)(data->first_xa
						+ data->xa * data->i)) / PXL;
			data->check_x = (data->pl_x / PXL) + (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->pl_x + (int)(data->first_ya
						+ data->ya * data->o)) / PXL;
			data->check_y = (data->pl_y / PXL) + (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_nw(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->pl_y - (int)(data->first_xa
						+ data->xa * data->i + 1.00)) / PXL;
			data->check_x = (data->pl_x / PXL) - (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->pl_x - (int)(data->first_ya
						+ data->ya * data->o + 1.00)) / PXL;
			data->check_y = (data->pl_y / PXL) - (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_ne(t_data *data)
{
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->pl_y + (int)(data->first_xa
						+ data->xa * data->i)) / PXL;
			data->check_x = (data->pl_x / PXL) - (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->pl_x - (int)(data->first_ya
						+ (data->ya * data->o) + 1.00)) / PXL;
			data->check_y = (data->pl_y / PXL) + (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_init_wall_img(t_data *data)
{
	data->wall_n = mlx_xpm_file_to_image(data->mlx_ptr, data->no_texture,
			&data->wall_n_w, &data->wall_n_height);
	data->wall_e = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->ea_texture, &data->wall_e_w, &data->wall_e_height);
	data->wall_s = mlx_xpm_file_to_image(data->mlx_ptr, data->so_texture,
			&data->wall_s_w, &data->wall_s_height);
	data->wall_w = mlx_xpm_file_to_image(data->mlx_ptr, data->we_texture,
			&data->wall_w_w, &data->wall_w_height);
	if (data->wall_n == NULL || data->wall_e == NULL
		|| data->wall_s == NULL || data->wall_w == NULL)
		ft_exit_failure(data, 4, "\n      Error in open textures files\n", \
		"TEXTURES KO ");
	data->wall_n_addr = mlx_get_data_addr(data->wall_n, &data->wall_n_bpp,
			&data->wall_n_line_l, &data->wall_n_endian);
	data->wall_e_addr = mlx_get_data_addr(data->wall_e, &data->wall_e_bpp,
			&data->wall_e_line_l, &data->wall_e_endian);
	data->wall_s_addr = mlx_get_data_addr(data->wall_s, &data->wall_s_bpp,
			&data->wall_s_line_l, &data->wall_s_endian);
	data->wall_w_addr = mlx_get_data_addr(data->wall_w, &data->wall_w_bpp,
			&data->wall_w_line_l, &data->wall_w_endian);
}
