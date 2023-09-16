/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:47:16 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/16 16:13:27 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_quit2(t_data *data)
{
// 	 ft_printf("%s\n", data->map->map[6]);
	// int	i;
	
// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_display(data->mlx_ptr);

	// i = -1;
	// while (data->map->map[++i])
	// 	free(data->map->map[i]);
// 	free(data->map->map);
	// free(data->map);
// 	free(data->mlx_ptr);
// 	free(data->mlx);
	// free(data->image);
	free(data);
	exit (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		ft_quit2(data);

		// exit(0);
	}
	// if (keysym == 119 || keysym == 65362)
	// 	if (data->map[data->pl_y - 1][data->pl_x] != '1')
	// 		ft_move_up(data);
	// if (keysym == 115 || keysym == 65364)
	// 	if (data->map[data->pl_y + 1][data->pl_x] != '1')
	// 		ft_move_down(data);
	// if (keysym == 97 || keysym == 65361)
	// 	if (data->map[data->pl_y][data->pl_x - 1] != '1')
	// 		ft_move_left(data);
	// if (keysym == 100 || keysym == 65363)
	// 	if (data->map[data->pl_y][data->pl_x + 1] != '1')
	// 		ft_move_right(data);
	return (0);
}

int	init_params(t_data *data)
{
	char *s;

	data->exit = 1;
	data->mlx->scale = 100;
	data->mlx->center_x = 0.0;
	data->mlx->center_y = 0.0;
	data->mlx->x = WINDOW_W;
	data->mlx->y = WINDOW_H;
	data->mlx->pxl = 50;
	s = get_map_color("42\0", 4, data);
	data->map->color_map_hex_F = ft_htoi(s);
	free(s);
	s = get_map_color("42\0", 5, data);
	data->map->color_map_hex_C = ft_htoi(s);
	free(s);
	return (0);
}

// int	rerender(t_data *data)
// {
// 	mlx_destroy_image(data->mlx_ptr, data->image->image_ptr);
// 	data->image->image_ptr = mlx_new_image(data->mlx_ptr, WINDOW_W, WINDOW_H);
// 	data->image->data_addr = (int *)mlx_get_data_addr(data->image->image_ptr,
// 			&(data->image->bits_per_pixel), &(data->image->size_line),
// 			&(data->image->endian));
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image->image_ptr, 0, 0);
// 	return (0);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length + x * (data->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_fill_floor(t_data *data)
{
	data->image->image_ptr = mlx_new_image(data->mlx_ptr, data->mlx->x, data->mlx->y);
	data->image->addr = mlx_get_data_addr(data->image->image_ptr, &data->image->bits_per_pixel,
							&data->image->line_length, &data->image->endian);
	data->mlx->y = 0;
	while ((data->mlx->y) < WINDOW_H)
	{
		data->mlx->x = 0;
		while ((data->mlx->x) < WINDOW_W)
		{
			if (data->mlx->y < WINDOW_H / 2)
				my_mlx_pixel_put(data, data->mlx->x, data->mlx->y, 0xFF0000);
			else
				my_mlx_pixel_put(data, data->mlx->x, data->mlx->y, 0xFF00FF);
			data->mlx->x++;
		}
		data->mlx->y++;
	}
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->image->image_ptr, 
								0, 0);
	mlx_destroy_image(data->mlx_ptr, data->image->image_ptr);
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
			WINDOW_H, "Cub3d");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	mlx_hook(data->win_ptr, 2, 1L << 0, &handle_keypress, data->mlx);
	// mlx_hook(data->win_ptr, 17, 1L << 0, &ft_quit2, data->mlx);

	mlx_loop_hook(data->mlx_ptr, &render, data->mlx);
	// mlx_mouse_hook(data->win_ptr, mouse_controls, &data->mlx);
	ft_fill_floor(data);
	// ft_raytraycing(data);

	mlx_loop(data->mlx_ptr);
	// mlx_destroy_display(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	ft_printf("%s\n", argv[0]);
	t_data	*data;

	if (argc > 1)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->map = (t_map *)malloc(sizeof(t_map));
		if (ft_check(argc, argv, data) == 1)
			ft_clean_when_verif_map_ko(data);
		data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
		init_params(data);
		data->image = (t_image *)malloc(sizeof(t_image));
		// test_gps(data);
		ft_create_window(data);
		// game_over(data);
	}
	else
		return (err("ou est la carte ?\n"));
	return (0);
}
