/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:06:20 by kaly              #+#    #+#             */
/*   Updated: 2023/07/27 17:47:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* la fonction free chars vide un tableau de int et le free*/

void	ft_free_ints(int *i)
{
	while (i)
	{
		*i = 0;
		i++;
	}
	free(i);
}
