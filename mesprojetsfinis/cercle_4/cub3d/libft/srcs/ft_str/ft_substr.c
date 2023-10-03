/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:10:33 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:05:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** Alloue (avec malloc) et retourne une chaîne de caractères issue de la chaîne
** ’s’. Cette nouvelle chaîne commence à l’index ’start’ et a pour taille
** maximale ’len’.
**
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_length;
	size_t	end;

	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	end = 0;
	if ((size_t)start > s_length)
		return (ft_strdup(""));
	if (start < s_length)
		end = s_length - start;
	if (end > len)
		end = len;
	sub = (char *) malloc (sizeof(char) * (end + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, end + 1);
	return (sub);
}
