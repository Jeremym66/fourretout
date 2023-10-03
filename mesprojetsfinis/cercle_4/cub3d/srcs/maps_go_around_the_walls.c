/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_go_around_the_walls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 12:28:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	go_around_the_walls(t_data *data)
{
	first_step(data);
	if (data->map[data->line][data->index + 1] == '1')
	{
		data->index++;
		if (go_around_the_walls2(data, 0))
			return (1);
		else
			return (0);
	}
	return (1);
}

void	first_step(t_data *data)
{
	data->line = data->map_first_line;
	data->index = 0;
	while (data->map[data->line][data->index] == ' ')
		data->index++;
	if (data->map[data->line][data->index] == '1')
		data->first_index = data->index;
	data->map[data->line][data->index] = '4';
}

int	go_around_the_walls2(t_data *d, int i)
{
	while (d->line != d->map_first_line || d->index != d->first_index)
	{
		i++;
		if (test_map_ok(d, i))
			return (0);
		else if (verif_sides(d, 1, '1'))
			go_sides(d, 1, '2');
		else if (verif_up_or_down(d, -1, '1'))
			go_up_or_down(d, -1, '2');
		else if (verif_sides(d, -1, '1'))
			go_sides(d, -1, '2');
		else if (verif_up_or_down(d, 1, '1'))
			go_up_or_down(d, 1, '2');
		else if (verif_up_or_down(d, 1, '2'))
			go_up_or_down(d, 1, '3');
		else if (verif_sides(d, -1, '2'))
			go_sides(d, -1, '3');
		else if (verif_up_or_down(d, -1, '2'))
			go_up_or_down(d, -1, '3');
		else if (verif_sides(d, 1, '2'))
			go_sides(d, 1, '3');
		else
			return (1);
	}
	return (0);
}
