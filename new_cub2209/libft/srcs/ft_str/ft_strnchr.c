/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:15:37 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/25 11:21:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** La fonction strchr renvoie le nombre du caractère c dans la chaîne s.
**
*/

int	ft_strnchr(const char *s, int c)
{
	unsigned int	index;
	unsigned int	number;

	index = 0;
	number = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			number++;
		index++;
	}
	if (s[index] == c)
		number++;
	return (number);
}
