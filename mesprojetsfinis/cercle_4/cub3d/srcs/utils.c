/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:20:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/28 10:59:00 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **map, int i)
{
	while (map[++i])
		ft_printf("%d :\t%s", i, map[i]);
}

int	empty_line(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (1);
	while (c[i])
	{
		if (c[i] == 32 || (c[i] == 9) || (c[i] == 10))
			i++;
		else
			return (0);
	}
	return (1);
}

int	get_k(int i)
{
	if (i < 10)
		return (2);
	else if (i < 100)
		return (3);
	else
		return (4);
	return (0);
}
