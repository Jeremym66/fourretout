/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_mooves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/27 15:04:48 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_back(t_data *data)
{
	data->anglerad = data->player_orient * (M_PI / 180.00);
	data->xa = PXL * sin(data->anglerad) * (-1);
	data->ya = PXL * cos(data->anglerad);
	data->check_y = (data->pl_y - (int)data->ya) / PXL;
	data->check_x = (data->pl_x - (int)data->xa) / PXL;
	if (data->map[(int)data->check_x][(int)data->check_y] != '1')
	{
		data->pl_x -= (int)data->xa / 5;
		data->pl_y -= (int)data->ya / 5;
	}
}

void	ft_move_up(t_data *data)
{
	data->anglerad = data->player_orient * (M_PI / 180.00);
	data->xa = PXL * sin(data->anglerad) * (-1);
	data->ya = PXL * cos(data->anglerad);
	data->check_y = (data->pl_y + (int)data->ya) / PXL;
	data->check_x = (data->pl_x + (int)data->xa) / PXL;
	if (data->map[(int)data->check_x][(int)data->check_y] != '1')
	{
		data->pl_x += (int)data->xa / 5;
		data->pl_y += (int)data->ya / 5;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_quit(data);
	if (keysym == 65362)
		data->horizon += 30;
	if (keysym == 65364)
		if (data->horizon > WINDOW_H / 3)
			data->horizon -= 30;
	if (keysym == 119)
		ft_move_up(data);
	if (keysym == 115)
		ft_move_back(data);
	if (keysym == 100)
		ft_strafe_right(data);
	if (keysym == 97)
		ft_strafe_left(data);
	if (keysym == 65361)
		ft_turn_left(data);
	if (keysym == 65363)
		ft_turn_right(data);
	ft_fill_floor(data);
	return (0);
}
