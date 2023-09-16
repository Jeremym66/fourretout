/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:04:44 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/10 14:25:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** la fonction ft_isspaces renvoie 1 si le char * n'est composé que d'espaces
** ou équivalent
*/

int	ft_isspace(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == 32 || (c[i] <= 13 && c[i] >= 9))
			i++;
		else
			return (0);
	}
	return (1);
}
