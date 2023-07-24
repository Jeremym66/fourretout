/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:43:50 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:04:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
** 
** Alloue avec malloc et retourne une nouvelle chaîne, résultat de la
** concaténation de s1 et s2. Renvoi la nouvelle chaîne de caractères, NULL si
** l’allocation échoue.
**
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*sresult;
	size_t		s1_length;
	size_t		s2_length;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	sresult = malloc (sizeof(char) * (s1_length + s2_length + 1));
	if (sresult == NULL)
		return (NULL);
	ft_memmove(sresult, s1, s1_length);
	ft_memmove((sresult + s1_length), s2, s2_length);
	sresult[(s1_length + s2_length)] = '\0';
	return (sresult);
}
