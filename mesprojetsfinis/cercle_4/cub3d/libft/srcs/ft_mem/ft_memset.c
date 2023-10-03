/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:17:48 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/23 20:31:07 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** La fonction memset remplit les n premiers octets de la zone
** mémoire pointée par b avec l'octet c.
**
** VALEUR RENVOYEE : La fonction memset renvoie un pointeur sur la zone
** mémoire b.
**
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
