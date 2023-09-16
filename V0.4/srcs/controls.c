/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:57:13 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/16 15:51:27 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libmlx/mlx_int.h"
#include "../libmlx/mlx.h"

void	moving(int key, t_data *data)
{
	if (key == UP)
		data->mlx->center_y -= (double)(MOVING_FACTOR) / (data->mlx->scale);
	if (key == DOWN)
		data->mlx->center_y += (double)(MOVING_FACTOR) / (data->mlx->scale);
	if (key == LEFT)
		data->mlx->center_x -= (double)(MOVING_FACTOR) / (data->mlx->scale);
	if (key == RIGHT)
		data->mlx->center_x += (double)(MOVING_FACTOR) / (data->mlx->scale);
}

// int	key_controls(int key, t_data *data)
// {
// 	if (key == 65307)
// 		mlx_close(data);
// 	else if (key == PLUS)
// 		data->mlx->scale *= SCALE_FACTOR;
// 	else if (key == MINUS)
// 		data->mlx->scale /= SCALE_FACTOR;
// 	else if (key == R_KEY)
// 		init_params(data);
// 	else if (key >= 65361 && key <= 65364)
// 		moving(key, data);
// 	else if (key == L_KEY)
// 		data->mlx->max_iter += 500;
// 	else if (key == K_KEY && data->mlx->max_iter >= 600)
// 		data->mlx->max_iter -= 500;
// 	else if (key == N_KEY)
// 		init_params(data);
// 	else
// 		return (0);
// 	rerender(data);
// 	return (1);
// }

// int	mouse_controls(int button, int x, int y, t_data *data)
// {
// 	mlx_mouse_get_pos(data->mlx->mlx, data->mlx->window, &x, &y);
// 	if (x != data->mlx->center_x || y != data->mlx->center_y)
// 	{
// 		data->mlx->center_y = ((y - WINDOW_H / 2) / data->mlx->scale + data->mlx->center_y);
// 		data->mlx->center_x = ((x - WINDOW_W / 2) / data->mlx->scale + data->mlx->center_x);
// 	}
// 	if (button == MOUSE_LEFT || button == WHEEL_DOWN)
// 	{
// 		data->mlx->scale *= SCALE_FACTOR;
// 		data->mlx->max_iter += SCALE_ITER;
// 	}
// 	if (button == MOUSE_RIGHT || button == WHEEL_UP)
// 	{
// 		data->mlx->scale /= SCALE_FACTOR;
// 		data->mlx->max_iter -= SCALE_ITER;
// 	}
// 	rerender(data);
// 	return (1);
// }
