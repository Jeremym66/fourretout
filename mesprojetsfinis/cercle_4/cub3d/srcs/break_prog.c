/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:37:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/29 11:01:40 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clean_map_and_inside(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
}

void	ft_clean_textures(t_data *data, int i)
{
	if (i >= 4)
		free(data->ea_texture);
	if (i >= 3)
		free(data->we_texture);
	if (i >= 2)
		free(data->so_texture);
	if (i >= 1)
		free(data->no_texture);
}

void	ft_clean_fc_color(t_data *data, int i)
{
	if (i == 1)
		free(data->floor_hex_color);
	if (i == 2)
		free(data->ceiling_hex_color);
	if (i == 3)
	{
		free(data->floor_hex_color);
		free(data->ceiling_hex_color);
	}
}

void	ft_clean_split_color(t_data *data, int i, int j)
{
	if (i == 1)
	{
		while (data->split_color_c[++j])
			free(data->split_color_c[j]);
		free(data->split_color_c);
	}
	if (i == 2)
	{
		j = -1;
		while (data->split_color_f[++j])
			free(data->split_color_f[j]);
		free(data->split_color_f);
	}
	if (i == 3)
	{
		while (data->split_color_c[++j])
			free(data->split_color_c[j]);
		free(data->split_color_c);
		j = -1;
		while (data->split_color_f[++j])
			free(data->split_color_f[j]);
		free(data->split_color_f);
	}
}
