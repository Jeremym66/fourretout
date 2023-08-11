/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:56:34 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:02:42 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** La fonction memcmp() compare les n premiers octets des zones mémoire s1 et
** s2. Elle renvoie un entier inférieur, égal, ou supérieur à zéro, si s1 est
** respectivement inférieure, égale ou supérieur à s2.
** 
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*scopy1;
	unsigned char	*scopy2;

	scopy1 = (unsigned char *)s1;
	scopy2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*scopy1 == *scopy2 && ++i < n)
	{
		scopy1++;
		scopy2++;
	}
	return ((int)(*scopy1 - *scopy2));
}
