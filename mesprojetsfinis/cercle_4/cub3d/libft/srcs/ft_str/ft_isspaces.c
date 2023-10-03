/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:04:44 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/05 09:15:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** la fonction ft_isspaces renvoie 1 si elle est un espace (32) ou un \t, \n
** \v, \f ou \r
*/

int	ft_isspaces(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}
