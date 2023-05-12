/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:03:55 by kaly              #+#    #+#             */
/*   Updated: 2023/05/06 13:06:31 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//#include "../lib/minilibx/mlx.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	printf("Keyrelease: %d\n", keysym);
	data->release++;
	return (0);
}

void    ft_fill_floor(t_data *data)
{
        data->y = 0;
	data->file = mlx_xpm_file_to_image(data->mlx_ptr,
		"../img/floor.xpm", &data->pxl, &data->pxl);
        while ((data->y) < (data->map_y))
        {
                data->x = 0;
                while ((data->x) < (data->map_x))
                {
                        mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
                                data->file, data->pxl * data->x,
                                data->pxl * data->y);

                        data->x++;
                }
                data->y++;
        }
        mlx_destroy_image(data->mlx_ptr, data->file);
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			WINDOW_LARGE / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
//	game->file = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &data->pxl, &data->pxl);
//	mlx_put_image_to_window (data->mlx, data->mlx_win, data->file, data->pxl * data->x,
//		data->pxl * data->y);
//		ft_fill_floor(data);
		data->file = mlx_xpm_file_to_image(data->mlx_ptr, "../img/cat.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file, 100, 100);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file, 150, 150);
		mlx_destroy_image(data->mlx_ptr, data->file);
		data->file = mlx_xpm_file_to_image(data->mlx_ptr, "../img/lasagnes.xpm", &data->pxl, &data->pxl);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->file, 200, 300);
		mlx_destroy_image(data->mlx_ptr, data->file);
	}
	return (0);
}

void	init_data(t_data *data)
{	
	data->pxl = 50;
	data->map_x = 10;
 	data->map_y = 10;
	data->x = 0;
	data->y = 0;
}

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
    	if (!data)
        	return (MLX_ERROR);
	init_data(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->pxl * data->map_x,
		data->pxl * data->map_y, "Garfield Version 1.0");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	ft_fill_floor(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}
