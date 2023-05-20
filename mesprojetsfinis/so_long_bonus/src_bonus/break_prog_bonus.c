/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_prog_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:37:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/20 17:37:20 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_quit(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	i = -1;
	while (data->p[++i])
		free(data->p[i]);
	free(data->p);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}

int	ft_quit2(t_data *data)
{
	int	i;

	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	i = -1;
	while (data->p[++i])
		free(data->p[i]);
	free(data->p);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}
