/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/20 16:00:23 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_coordonate(t_data *data)
{
	int	i;
	int	j;

	i = 6;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W')
			{
				data->player_x = i * PXL + 50;
				data->player_y = j * PXL + 50;
				if (data->map[i][j] == 'E')
					data->player_orient = 0.01;
				else if (data->map[i][j] == 'N')
					data->player_orient = 90.01;
				else if (data->map[i][j] == 'W')
					data->player_orient = 180.01;
				else
					data->player_orient = -90.01;
				ft_printf("player x : %d\n", data->player_x);
				ft_printf("player y : %d\n", data->player_y);
				return ;
			}
			j++;
		}
		i++;
	}

}

// int	where_s_the_wall(int x, int y, int angle, t_data *data)
// {
// 	int	dist;

// 	dist = 0;
// 	if (angle < 90)
// 	{
// 		while (x - dist >= data->map->ligne_zero && y <= data->map->longueur_de_ligne[x - 5])
// 		{
// 			ft_printf("je teste la ligne %d\n", (x - dist));
// 			ft_printf("la ligne est : %s", data->map[x - dist]);
// 			ft_printf("je teste le char numero %d\n", y);
// 			ft_printf("qui est : %d\n", (data->map[x - dist][y] - 48));
// 			if (data->map[x - dist][y] == '1')
// 				return (dist);
// 			dist++;
// 		}
// 		ft_printf("je n'ai pas trouvé de 1\n");
// 		return (data->map->ligne_zero);
// 	}
// 	else if (angle < 180)
// 	{
// 		while (1)
// 		{
// 			if (data->map[x - dist][y] == 1)
// 				return (dist);
// 			dist++;
// 		}
// 	}
// 	else if (angle > 270)
// 	{
// 		while (1)
// 		{
// 			if (data->map[x - dist][y] == 1)
// 				return (dist);
// 			dist++;
// 		}
// 	}
// 	else
// 	{
// 		while (1)
// 		{
// 			if (data->map[x][y - dist] == 1)
// 				return (dist);
// 			dist++;
// 		}
// 	}
// 	return (dist);
// }

// void	test_gps(t_data *data)
// {
// 	int i;
// 	int	j;
// 	int	k;
// 	int	res;

// 	// ft_printf("test avec coord dans un mur\n");
// 	// i = 10;
// 	// j = 3;
// 	// k = 0;
// 	// res = where_s_the_wall(i, j, k, data);
// 	// ft_printf("x = %d, y = %d, angle de vue = %d et resultat = %d", i, j, k, res);

// 	// ft_printf("test avec un perso sur un 0\n");
// 	// i = 9;
// 	// j = 4;
// 	// k = 0;
// 	// res = where_s_the_wall(i, j, k, data);
// 	// ft_printf("x = %d, y = %d, angle de vue = %d et resultat = %d", i, j, k, res);

// 	ft_printf("test avec un perso sur un 0 et un angle\n");
// 	i = 9;
// 	j = 4;
// 	k = 80;
// 	res = where_s_the_wall(i, j, k, data);
// 	ft_printf("x = %d, y = %d, angle de vue = %d et resultat = %d\n", i, j, k, res);
// }

// int	player_can_moove(t_data *data)
// {
// 	if ((data->map[data->map->player_coord[0] - 1][data->map->player_coord[1]] == 49)
// 		&& (data->map[data->map->player_coord[0]][data->map->player_coord[1] - 1] == 49)
// 		&& (data->map[data->map->player_coord[0]][data->map->player_coord[1] + 1] == 49)
// 		&& (data->map[data->map->player_coord[0] + 1][data->map->player_coord[1]] == 49))
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
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] =='E' || data->map[i][j] =='N'
				|| data->map[i][j] =='S' || data->map[i][j] =='W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}