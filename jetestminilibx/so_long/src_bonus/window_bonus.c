/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/05/19 20:14:24 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_quit2(data);
	if (keysym == 119 || keysym == 65362)
		if (data->map[data->pl_y - 1][data->pl_x] != '1')
			ft_move_up(data);
	if (keysym == 115 || keysym == 65364)
		if (data->map[data->pl_y + 1][data->pl_x] != '1')
			ft_move_down(data);
	if (keysym == 97 || keysym == 65361)
		if (data->map[data->pl_y][data->pl_x - 1] != '1')
			ft_move_left(data);
	if (keysym == 100 || keysym == 65363)
		if (data->map[data->pl_y][data->pl_x + 1] != '1')
			ft_move_right(data);
	return (0);
}

void	ft_fill_floor(t_data *data)
{
	data->y = 0;
	data->file = mlx_xpm_file_to_image(data->mlx_ptr,
			"./img/fond2.xpm", &data->pxl, &data->pxl);
	while ((data->y) < (data->map_y))
	{
		data->x = 0;
		while ((data->x) < (data->map_x))
		{
			mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
				data->file, PXL * data->x, PXL * data->y);
			data->x++;
		}
		data->y++;
	}
	mlx_destroy_image(data->mlx_ptr, data->file);
}

void	ft_complete_img(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		data->y = 0;
		while ((data->y) < (data->map_y))
		{
			data->x = 0;
			while ((data->x) < (data->map_x))
			{
				if (data->map[data->y][data->x] == '1')
					ft_put_limits(data);
				if (data->map[data->y][data->x] == 'C')
					ft_put_collect(data);
				if (data->map[data->y][data->x] == 'P')
					ft_put_player(data);
				if (data->map[data->y][data->x] == 'E')
					ft_put_exit(data);
				if (data->map[data->y][data->x] == 'A')
					ft_put_ennemy(data);
				data->x++;
			}
			data->y++;
		}
	}
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		if (data->exit == 0)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
			ft_printf("You Win !!\n");
		}
	}
	if (data->collect == 0 && data->exit_is_open == 0)
	{
		data->exit_is_open = 1;
		data->x = data->exit_x;
		data->y = data->exit_y;
		ft_put_exit(data);
	}
	return (0);
}

void	ft_create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, PXL * data->map_x,
			PXL * data->map_y, "Zelda");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	mlx_hook(data->win_ptr, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &ft_quit2, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	ft_fill_floor(data);
	ft_complete_img(data);
	ft_move_display(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}
