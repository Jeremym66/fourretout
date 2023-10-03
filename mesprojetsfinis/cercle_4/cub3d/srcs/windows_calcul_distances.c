/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_calcul_distances.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/27 15:19:50 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_distance(t_data *data)
{
	int	i;

	while (data->x < WINDOW_W)
	{
		if (data->orient >= 180)
			data->orient -= 360.00;
		if (data->orient <= -180)
			data->orient += 360.00;
		ft_init_delta(data);
		i = -1;
		data->y = data->horizon - (PXL / data->dist * 350);
		while ((data->y) < data->horizon + (PXL / data->dist * 350))
		{
			if (++i == 0)
				data->origin_y = data->y;
			if (data->y >= 0 && data->y < WINDOW_H)
				calcul_distance_part_one(data);
			data->y++;
		}
		data->x++;
		data->beta -= data->scale;
		data->orient -= data->scale;
	}
}

void	calcul_distance_part_one(t_data *data)
{
	data->draw_y = data->y - data->origin_y;
	if (data->orient > 0 && data->orient < 90)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->pixel_x = ((data->pl_y + (int)(data->first_xa + data->xa
							* data->i)) % PXL) * data->wall_n_w / PXL;
			data->pixel_y = data->draw_y * data->wall_n_height / ((data->horizon
						- data->origin_y) * 2);
			my_mlx_pixel(data, data->x, data->y, pix_text(data,
					data->wall_n_addr, data->wall_n_line_l, data->wall_n_bpp));
		}
		else
		{
			data->pixel_x = ((data->pl_x - (int)(data->first_ya + data->ya
							* data->o + 1.00)) % PXL) * data->wall_e_w / PXL;
			data->pixel_y = data->draw_y * data->wall_e_height / ((data->horizon
						- data->origin_y) * 2);
			my_mlx_pixel(data, data->x, data->y, pix_text(data, \
			data->wall_e_addr, data->wall_e_line_l, data->wall_e_bpp));
		}
	}
	else
		calcul_distance_part_two(data);
}

void	calcul_distance_part_two(t_data *data)
{
	if (data->orient > 90)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->pixel_x = ((data->pl_y - (int)(data->first_xa + data->xa
							* data->i + 1.00)) % PXL) * data->wall_n_w / PXL;
			data->pixel_y = data->draw_y * data->wall_n_height / ((data->horizon
						- data->origin_y) * 2);
			my_mlx_pixel(data, data->x, data->y, pix_text(data, \
			data->wall_n_addr, data->wall_n_line_l, data->wall_n_bpp));
		}
		else
		{
			data->pixel_x = ((data->pl_x - (int)(data->first_ya + data->ya
							* data->o + 1.00)) % PXL) * data->wall_w_w / PXL;
			data->pixel_y = data->draw_y * data->wall_w_height / ((data->horizon
						- data->origin_y) * 2);
			my_mlx_pixel(data, data->x, data->y, pix_text(data, \
			data->wall_w_addr, data->wall_w_line_l, data->wall_w_bpp));
		}
	}
	else
		calcul_distance_part_three(data);
}

void	calcul_distance_part_three(t_data *data)
{
	if (data->orient < 0 && data->orient > -90)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->pixel_x = ((data->pl_y + (int)(data->first_xa + data->xa
							* data->i)) % PXL) * data->wall_s_w / PXL;
			data->pixel_y = data->draw_y * data->wall_s_height / ((data->horizon
						- data->origin_y) * 2);
			my_mlx_pixel(data, data->x, data->y, pix_text(data, \
			data->wall_s_addr, data->wall_s_line_l, data->wall_s_bpp));
		}
		else
		{
			data->pixel_x = ((data->pl_x + (int)(data->first_ya + data->ya
							* data->o)) % PXL) * data->wall_e_w / PXL;
			data->pixel_y = data->draw_y * data->wall_e_height / ((data->horizon
						- data->origin_y) * 2);
			my_mlx_pixel(data, data->x, data->y, pix_text(data, \
			data->wall_e_addr, data->wall_e_line_l, data->wall_e_bpp));
		}
	}
	else
		calcul_distance_part_four(data);
}

void	calcul_distance_part_four(t_data *data)
{
	if (data->dist_x <= data->dist_y)
	{
		data->pixel_x = ((data->pl_y - (int)(data->first_xa + data->xa
						* data->i + 1.00)) % PXL) * data->wall_s_w / PXL;
		data->pixel_y = data->draw_y * data->wall_s_height / ((data->horizon - \
		data->origin_y) * 2);
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_s_addr, \
		data->wall_s_line_l, data->wall_s_bpp));
	}
	else
	{
		data->pixel_x = ((data->pl_x + (int)(data->first_ya + data->ya
						* data->o)) % PXL) * data->wall_w_w / PXL;
		data->pixel_y = data->draw_y * data->wall_w_height / ((data->horizon - \
		data->origin_y) * 2);
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_w_addr, \
		data->wall_w_line_l, data->wall_w_bpp));
	}
}
