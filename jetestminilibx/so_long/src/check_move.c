/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:28:01 by kaly              #+#    #+#             */
/*   Updated: 2023/05/12 17:37:40 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_move(t_data *data, char dest)
{
	if (dest == 'E')
	{
		if (data->collect == 0)
		{
			data->exit = 0;
			return (1);
		}
		if (data->collect > 0)
			return (0);
	}
	if (dest == 'C')
	{
		data->collect--;
		ft_printf("There are %d collectibles left to find\n", data->collect);
	}
	return (1);
}
