/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/14 16:39:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_coordonate(t_data *data)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'E' || data->map->map[i][j] == 'N' || data->map->map[i][j] == 'S'
				|| data->map->map[i][j] == 'W')
			{
				data->map->player_coord[0] = i;
				data->map->player_coord[1] = j;
				data->map->player_start_orient = data->map->map[i][j];
				if (data->map->map[i][j] == 'E')
					data->map->player_see = 90;
				else if (data->map->map[i][j] == 'N')
					data->map->player_see = 0;
				else if (data->map->map[i][j] == 'S')
					data->map->player_see = 180;
				else
					data->map->player_see = 270;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	where_s_the_wall(int x, int y, int angle, t_data *data)
{
	int	dist;

	dist = 0;
	if (angle < 90)
	{
		while (x - dist >= data->map->ligne_zero && y <= data->map->longueur_de_ligne[x - 5])
		{
			ft_printf("je teste la ligne %d\n", (x - dist));
			ft_printf("la ligne est : %s", data->map->map[x - dist]);
			ft_printf("je teste le char numero %d\n", y);
			ft_printf("qui est : %d\n", (data->map->map[x - dist][y] - 48));
			if (data->map->map[x - dist][y] == '1')
				return (dist);
			dist++;
		}
		ft_printf("je n'ai pas trouvé de 1\n");
		return (data->map->ligne_zero);
	}
	else if (angle < 180)
	{
		while (1)
		{
			if (data->map->map[x - dist][y] == 1)
				return (dist);
			dist++;
		}
	}
	else if (angle > 270)
	{
		while (1)
		{
			if (data->map->map[x - dist][y] == 1)
				return (dist);
			dist++;
		}
	}
	else
	{
		while (1)
		{
			if (data->map->map[x][y - dist] == 1)
				return (dist);
			dist++;
		}
	}
	return (dist);
}

void	test_gps(t_data *data)
{
	int i;
	int	j;
	int	k;
	int	res;

	// ft_printf("test avec coord dans un mur\n");
	// i = 10;
	// j = 3;
	// k = 0;
	// res = where_s_the_wall(i, j, k, data);
	// ft_printf("x = %d, y = %d, angle de vue = %d et resultat = %d", i, j, k, res);

	// ft_printf("test avec un perso sur un 0\n");
	// i = 9;
	// j = 4;
	// k = 0;
	// res = where_s_the_wall(i, j, k, data);
	// ft_printf("x = %d, y = %d, angle de vue = %d et resultat = %d", i, j, k, res);

	ft_printf("test avec un perso sur un 0 et un angle\n");
	i = 9;
	j = 4;
	k = 80;
	res = where_s_the_wall(i, j, k, data);
	ft_printf("x = %d, y = %d, angle de vue = %d et resultat = %d", i, j, k, res);
}

// int	player_can_moove(t_data *data)
// {
// 	if ((data->map->map[data->map->player_coord[0] - 1][data->map->player_coord[1]] == 49)
// 		&& (data->map->map[data->map->player_coord[0]][data->map->player_coord[1] - 1] == 49)
// 		&& (data->map->map[data->map->player_coord[0]][data->map->player_coord[1] + 1] == 49)
// 		&& (data->map->map[data->map->player_coord[0] + 1][data->map->player_coord[1]] == 49))
// 		return (1);
// 	return (0);
// }

int	only_one_player(t_data *data)
{
	int i;
	int	j;
	int	player;

	i = 6;
	player = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] =='E' || data->map->map[i][j] =='N'
				|| data->map->map[i][j] =='S' || data->map->map[i][j] =='W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}