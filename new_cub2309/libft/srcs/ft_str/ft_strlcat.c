/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:26:53 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:04:59 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** La fonction strlcat concatène des chaînes. Elles est conçue pour être un
** remplacement plus sûr, plus cohérent et moins sujets aux erreurs que strncat.
** Contrairement à cette fonction, strlcat prend la taille complète du tampon
** (pas seulement la longueur) et garantit la terminaison NUL du résultat (tant
** qu'il y a au moins un octet libre dans dst). Notez qu'un octet pour la valeur
** NUL doit être inclus dans size . Notez également que strlcat n'opère que sur
** les véritables chaînes ''C''. Cela signifie que pour strlcat, src et dst
** doivent être terminés par NUL.
** La fonction strlcat ajoute la chaîne terminée par NUL src à la fin de dst.
** Il ajoutera au plus size - strlen(dst) - 1 octets, terminant le résultat par
** NUL. 
**
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	if (!src || !size)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	i = 0;
	if (dest_len < (size - 1) && size > 0)
	{
		while (src[i] && (i + dest_len) < (size - 1))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = 0;
	}
	if (dest_len >= size)
		dest_len = size;
	return (src_len + dest_len);
}
