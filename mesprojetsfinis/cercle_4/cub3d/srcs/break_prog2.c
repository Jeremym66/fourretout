/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_prog2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:37:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/29 11:03:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clean(t_data *data, int i)
{
	if (i >= 4)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (i >= 3)
		ft_clean_fc_color(data, 3);
	if (i >= 2)
		ft_clean_split_color(data, 3, -1);
	if (i >= 1)
		ft_clean_textures(data, 5);
	if (i >= 0)
		ft_clean_map_and_inside(data);
	if (i == -1)
		free(data->map);
	free(data);
}

void	ft_exit_failure(t_data *data, int i, char *s_err, char *t_err)
{
	if (s_err != NULL)
		err(s_err);
	if (t_err != NULL)
		titre_err(t_err);
	ft_clean(data, i);
	exit(EXIT_FAILURE);
}

int	ft_quit(t_data *data)
{
	ft_printf("\n\n\033[31m");
	ft_printf("  %%%%%%%%    %%%%%%%%   %%%%   %%%%  %%%%%%%%%%%%\n");
	ft_printf(" %%%%      %%%%  %%%%  %%%%%% %%%%%%  %%%%\n");
	ft_printf(" %%%% %%%%%%  %%%%%%%%%%%%  %%%% %% %%%%  %%%%%%%%\n");
	ft_printf(" %%%%  %%%%  %%%%  %%%%  %%%%   %%%%  %%%%\n");
	ft_printf("  %%%%%%%%   %%%%  %%%%  %%%%   %%%%  %%%%%%%%%%%%\n");
	ft_printf("                                          \n");
	ft_printf("           %%%%%%%%   %%%%  %%%%  %%%%%%%%%%%%  %%%%%%%%%%\n");
	ft_printf("          %%%%  %%%%  %%%%  %%%%  %%%%      %%%%  %%%%\n");
	ft_printf("          %%%%  %%%%  %%%%  %%%%  %%%%%%%%    %%%%%%%%%%\n");
	ft_printf("          %%%%  %%%%   %%%%%%%%   %%%%      %%%%  %%%%\n");
	ft_printf("           %%%%%%%%     %%%%    %%%%%%%%%%%%  %%%%  %%%%\n");
	ft_printf("\033[0m\n");
	mlx_destroy_image(data->mlx_ptr, data->wall_n);
	mlx_destroy_image(data->mlx_ptr, data->wall_e);
	mlx_destroy_image(data->mlx_ptr, data->wall_s);
	mlx_destroy_image(data->mlx_ptr, data->wall_w);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_clean(data, 3);
	exit (0);
}
