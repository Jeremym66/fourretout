/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:37:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/16 17:44:16 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	ft_clean_when_verif_map_ko(t_data *data)
{
		int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	free(data);
	exit (EXIT_FAILURE);
}

int	ft_quit(t_data *data)
{
	ft_printf("..%%%%%%%%....%%%%%%%%...%%%%...%%%%..%%%%%%%%%%%%..........\n");
	ft_printf(".%%%%......%%%%..%%%%..%%%%%%.%%%%%%..%%%%..............\n");
	ft_printf(".%%%%.%%%%%%..%%%%%%%%%%%%..%%%%.%%.%%%%..%%%%%%%%............\n");
	ft_printf(".%%%%..%%%%..%%%%..%%%%..%%%%...%%%%..%%%%..............\n");
	ft_printf("..%%%%%%%%...%%%%..%%%%..%%%%...%%%%..%%%%%%%%%%%%..........\n");
	ft_printf("..........................................\n");
	ft_printf("...........%%%%%%%%...%%%%..%%%%..%%%%%%%%%%%%..%%%%%%%%%%...\n");
	ft_printf("..........%%%%..%%%%..%%%%..%%%%..%%%%......%%%%..%%%%..\n");
	ft_printf("..........%%%%..%%%%..%%%%..%%%%..%%%%%%%%....%%%%%%%%%%...\n");
	ft_printf("..........%%%%..%%%%...%%%%%%%%...%%%%......%%%%..%%%%..\n");
	ft_printf("...........%%%%%%%%.....%%%%....%%%%%%%%%%%%..%%%%..%%%%..\n");
	ft_printf("..........................................\n");
	int	i;

	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}
