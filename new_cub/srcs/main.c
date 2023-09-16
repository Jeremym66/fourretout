/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:18:13 by kaly              #+#    #+#             */
/*   Updated: 2023/09/16 18:57:14 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	char *s;
	
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->exit = 1;
	data->index_first_lane = 6;
	s = get_map_color("42\0", 4, data);
	data->color_map_hex_F = ft_htoi(s);
	free(s);
	s = get_map_color("42\0", 5, data);
	data->color_map_hex_C = ft_htoi(s);
	free(s);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	ft_check_arg(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		return (MLX_ERROR);
	if (ft_check(argc, argv, data) == 1)
		ft_clean_when_verif_map_ko(data);
	init_data(data);
	ft_create_window(data);
	// ft_quit(data);
	return (0);
}
