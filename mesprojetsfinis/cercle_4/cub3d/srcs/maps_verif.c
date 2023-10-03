/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 15:02:46 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	find_start_end_of_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i])
		i++;
	while (empty_line(data->map[i]))
		i--;
	if (ft_test_map_is_at_end(data, i))
		ft_exit_failure(data, 3, "\n\tla map doit etre a la fin\n", "MAP KO");
	data->map_last_line = i;
	while (begin_by_one(data->map[i]))
	{
		if (ends_by_one(data->map[i]))
			i--;
		else
			return (1);
	}
	data->map_first_line = i + 1;
	return (0);
}

int	begin_by_one(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == 49)
		return (1);
	return (0);
}

int	ends_by_one(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i -= 2;
	while (s[i] == ' ' || s[i] == '\t')
		i--;
	if (s[i] == '0')
		return (0);
	else if (s[i] == '1')
		return (1);
	return (0);
}

int	ft_test_map_is_at_end(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '1')
			j++;
		else
		{
			if (data->map[i][j] == '\n' || data->map[i][j] == 0)
				return (0);
			else
				return (1);
		}
	}
	return (0);
}
