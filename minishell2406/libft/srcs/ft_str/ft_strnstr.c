/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:08:25 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:05:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** The strnstr() function locates the first occurrence of the null-terminated
** string s2 in the string s1, where not more than n characters are searched.
** Characters that appear after a `\0' character are not searched.  Since the
** strnstr() function is a FreeBSD specific API, it should only be used when
** portability is not a concern.
**
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int		i;
	unsigned int		j;

	if (s2[0] == '\0')
		return ((char *)s1);
	if (!len)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (i + j < len && s1[i + j] == s2[j])
			{
				j++;
				if (!s2[j])
					return ((char *)&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
