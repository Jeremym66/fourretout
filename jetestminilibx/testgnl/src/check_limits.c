/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:55:25 by kaly              #+#    #+#             */
/*   Updated: 2023/05/06 23:02:01 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_up(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	data->map_x = i;
	return (0);
}

int	check_mid(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (1);
	i++;
	while (line[i])
	{
		if (line[i] == 'P')
			data->player++;
		else if (line[i] == 'C')
			data->collect++;
		else if (line[i] == 'E')
			data->exit++;
		else if (line[i] == '0' || line[i] == '1')
			;
		else
			return (1);
		i++;
	}
	if (line[i - 1] != '1')
		return (1);
	return (0);
}

int	ft_rect(t_data *data)
{
	int	i;
	int	j;
	int	large;

	i = 0;
	while (data->map[0][i])
		i++;
	large = i;
	j = 1;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
			i++;
		if (i != large)
			return (1);
		j++;
	}
	return (0);
}

int	ft_configuration(t_data *data)
{
	if (data->player != 1 || data->collect < 1 || data->exit != 1)
	{
		printf("Error\nNot enough player exit or collectibles\n");
		return (1);
	}
	return (0);
}

int	ft_check_limits(t_data *data)
{
	int	i;

	i = 0;
	if (check_up(data->map[i], data) == 1)
		return (1);
	i++;
	while (data->map[i])
	{
		if (check_mid(data->map[i], data) == 1)
			return (1);
		i++;
	}
	if (check_up(data->map[i - 1], data) == 1)
		return (1);
	data->map_y = i;
	if (ft_rect(data) == 1 || ft_configuration(data) == 1)
		return (1);
	return (0);
}