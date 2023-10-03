/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:04:51 by kaly              #+#    #+#             */
/*   Updated: 2023/09/29 10:29:44 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_comp_cub(char *arg, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
		i++;
	j = 0;
	while (str[j])
		j++;
	i -= j;
	j = 0;
	while (arg[i])
	{
		if (arg[i] != str[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		titre_err("CUB : KO");
		err("The commmand must be : ./cub3d <map.cub>\n");
		exit (EXIT_FAILURE);
	}
	if (ft_comp_cub(argv[1], ".cub") == 1)
	{
		titre_err("CUB : KO");
		err("      The map is not a \".cub\" map\n\n");
		exit (EXIT_FAILURE);
	}
}
