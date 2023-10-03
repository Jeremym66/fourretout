/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_verif_fc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 11:02:46 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	floor_ceiling_validation(t_data *data)
{
	if (floor_ceiling_found(data))
		return (err("  Error in search of Floor and Ceiling\n"));
	if (floor_format_validation(data))
	{
		ft_clean_split_color(data, 2, -1);
		return (err("\tFloor :\t\t\033[31mColor KO\033[0m\n"));
	}
	else
		ft_printf("\tFloor :\t\t\033[32mColor OK\033[0m\n");
	if (ceiling_format_validation(data))
	{
		ft_clean_split_color(data, 3, -1);
		return (err("\tCeiling :\t\033[31mColor KO\033[0m\n\n"));
	}
	else
		ft_printf("\tCeiling :\t\033[32mColor OK\033[0m\n");
	return (0);
}

int	floor_ceiling_found(t_data *data)
{
	data->line_floor = (search_floor_or_ceiling(data, "F "));
	data->line_ceiling = (search_floor_or_ceiling(data, "C "));
	if (data->line_floor == -1)
		return (titre_err(" FLOOR manquant "));
	else
		ft_printf("\tFloor :\t\t\033[32mPRESENT\033[0m\n");
	if (data->line_ceiling == -1)
		return (titre_err(" CEILING manquant "));
	else
		ft_printf("\tCeiling :\t\033[32mPRESENT\033[0m\n");
	return (0);
}

int	search_floor_or_ceiling(t_data *data, char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == c[0] && data->map[i][j + 1] == ' ')
			{
				if (c[0] == 'F')
					data->index_floor = j;
				else if (c[0] == 'C')
					data->index_ceiling = j;
				return (i);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

int	floor_format_validation(t_data *data)
{
	data->split_color_f = ft_split(data->map[data->line_floor], ',');
	if (empty_line(data->split_color_f[0]) || empty_line(data->split_color_f[1])
		|| empty_line(data->split_color_f[2]))
		return (1);
	data->floor_first_color = ft_atoi(data->split_color_f[0]);
	data->floor_second_color = ft_atoi(data->split_color_f[1]);
	data->floor_third_color = ft_atoi(data->split_color_f[2]);
	if ((data->floor_first_color < 0 || data->floor_first_color > 255)
		|| (data->floor_second_color < 0 || data->floor_second_color > 255)
		|| (data->floor_third_color < 0 || data->floor_third_color > 255))
		return (1);
	return (0);
}

int	ceiling_format_validation(t_data *data)
{
	data->split_color_c = ft_split(data->map[data->line_ceiling], ',');
	if (empty_line(data->split_color_c[0]) || empty_line(data->split_color_c[1])
		|| empty_line(data->split_color_c[2]))
		return (1);
	data->ceiling_first_color = ft_atoi(data->split_color_c[0]);
	data->ceiling_second_color = ft_atoi(data->split_color_c[1]);
	data->ceiling_third_color = ft_atoi(data->split_color_c[2]);
	if ((data->ceiling_first_color < 0 || data->ceiling_first_color > 255)
		|| (data->ceiling_second_color < 0 || data->ceiling_second_color > 255)
		|| (data->ceiling_third_color < 0 || data->ceiling_third_color > 255))
		return (1);
	return (0);
}
