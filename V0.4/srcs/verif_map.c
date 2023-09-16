/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/14 16:31:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] =='\t' || s[i] =='0' || s[i] =='1'
			|| s[i] =='E' || s[i] =='N' || s[i] =='S' || s[i] =='W')
		i++;
		else
			return (1);
	}
	return (0);
}

int	begin_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == 49)
		return (0);
	return (1);
}

int	ends_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i -= 2;
	while (s[i] == 32)
		i--;
	if (s[i] == 49)
		return (0);
	return (1);
}

int map_validation(t_data *data)
{
	int		i;

	i = 5;
	data->map->ligne_zero = i;
	while (data->map->map[++i])
	{
		if(is_valid_line(data->map->map[i]))
			return (titre_err(" car. incorrect "));
		else if (begin_by_one(data->map->map[i]) || ends_by_one(data->map->map[i]))
			return (titre_err(" mur ouvert "));
		data->map->longueur_de_ligne[i - 5] = ft_strlen(data->map->map[i]);
	}
	data->map->ligne_max = i - 1;
	return (0);
}
