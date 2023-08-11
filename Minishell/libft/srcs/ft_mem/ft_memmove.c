/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:17:48 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:02:51 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** La fonction memmove copie n octets depuis la zone mémoire src vers la zone
** mémoire dest. Les deux zones peuvent se chevaucher : la copie se passe comme
** si les octets de src étaient d'abord copiés dans une zone temporaire qui ne
** chevauche ni src ni dest, et les octets sont ensuite copiés de la zone
** temporaire vers dest.
**
** VALEUR RENVOYEE : La fonction memmove() renvoie un pointeur sur dest.
**
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*cpytempdest;
	const unsigned char	*cpytempsrc;
	size_t				i;

	cpytempsrc = src;
	cpytempdest = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (cpytempdest > cpytempsrc)
		while (len--)
			cpytempdest[len] = cpytempsrc[len];
	else
	{
		while (i < len)
		{
			cpytempdest[i] = cpytempsrc[i];
			i++;
		}
	}
	return (dest);
}
