/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/28 16:34:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	pix_text(t_data *data, char *addr, int line_lenght, int bpp)
{
	int	color;
	int	pixel;

	pixel = (data->pixel_y * line_lenght) + (data->pixel_x * (bpp / 8));
	color = *(unsigned int *)(addr + pixel);
	return (color);
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		if (data->exit == 0)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
	}
	return (0);
}

void	ft_create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W,
			WINDOW_H, "cub3D");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	ft_init_wall_img(data);
	mlx_hook(data->win_ptr, 2, 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &ft_quit, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	ft_fill_floor(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}

void	ft_fill_floor(t_data *data)
{
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->file = mlx_new_image(data->mlx_ptr, data->x, data->y);
	data->addr = mlx_get_data_addr(data->file, &data->bpp,
			&data->line_l, &data->endian);
	data->y = 0;
	while ((data->y) < WINDOW_H)
	{
		data->x = 0;
		while ((data->x) < WINDOW_W)
		{
			if (data->y < data->horizon)
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_c);
			else
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_f);
			data->x++;
		}
		data->y++;
	}
	data->beta = 30.00;
	data->orient = data->player_orient + data->beta;
	data->x = 0;
	calcul_distance(data);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->file);
}
