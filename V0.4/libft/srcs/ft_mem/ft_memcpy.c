/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:17:48 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:02:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** La fonction memcpy() copie n octets depuis la zone mémoire src
** vers la zone mémoire dest. Les deux zones ne doivent pas se chevaucher. Si
** c'est le cas, utilisez plutôt memmove.
**
** VALEUR RENVOYEE : La fonction memcpy() renvoie un pointeur sur dest.
** mémoire b.
**
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpytempsrc;
	char	*cpytempdest;
	size_t	i;

	if (src == dest)
		return (0);
	cpytempsrc = (char *)src;
	cpytempdest = (char *)dest;
	i = 0;
	while (i++ < n)
		*cpytempdest++ = *cpytempsrc++;
	return (dest);
}
