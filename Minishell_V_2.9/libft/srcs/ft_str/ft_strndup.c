/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:57:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 17:01:35 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** strndup malloc et copie s a partir de i
**
*/

char	*ft_strndup(const char *s, size_t i)
{
	char	*dup;
	size_t	length;
	size_t	j;

	j = 0;
	length = ft_strlen(s) + 1 - i;
	if (length == 0)
		return (NULL);
	dup = malloc(length * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i + j] && j < (length - 1))
	{
		dup[j] = s[i + j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
