/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 11:03:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_create_map(t_data *data, char **argv)
{
	int		i;
	int		fd;
	char	*str;

	data->map = (char **)malloc(sizeof(char *) * 10000);
	ft_printf("\e[1;1H\e[2J");
	titre(" TEST DE LA MAP ");
	if (!data->map)
		ft_exit_failure(data, 0, "erreur malloc, creation data->map\n", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		return (err("\tfichier map introuvable\n"));
	i = 0;
	str = ft_get_next_line(fd);
	if (!str)
		return (err("    erreur dans l'ouverture de la map\n"));
	while (str)
	{
		data->map[i++] = ft_strdup(str);
		free(str);
		str = ft_get_next_line(fd);
	}
	data->map[i] = 0;
	return (0);
}

int	ft_test_map(t_data *data)
{
	if (texture_validation(data))
		ft_exit_failure(data, 3, NULL, " TEXTURES :\t\t\033[31mKO\033[0m\n");
	if (floor_ceiling_validation(data))
		ft_exit_failure(data, 1, NULL, \
		" FLOOR OR CEILING :\t\t\033[31mKO\033[0m\n");
	fill_fc_color(data);
	if (find_start_end_of_map(data))
		ft_exit_failure(data, 3, NULL, \
		"MURS : KO ");
	resize_map(data);
	if (go_around_the_walls(data))
		ft_exit_failure(data, 3, NULL, \
		"MURS : KO ");
	else
		ft_printf("\tMurs :\t\t\033[32mOK\033[0m\n\n");
	ft_restore_map(data);
	titre(" MAP : OK ");
	return (0);
}

void	ft_restore_map(t_data *data)
{
	int	i;
	int	j;

	i = data->map_first_line;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2'
				|| data->map[i][j] == '3'
				|| data->map[i][j] == '4')
			{
				data->map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}
