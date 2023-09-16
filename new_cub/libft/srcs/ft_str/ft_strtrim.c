/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:27:51 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:05:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
** specified in ’set’ removed from the beginning and the end of the string.
**
*/

static int	find_char(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s1_trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && find_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && find_char(s1[end - 1], set))
		end--;
	s1_trimmed = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!s1_trimmed)
		return (NULL);
	i = 0;
	while (start < end)
		s1_trimmed[i++] = s1[start++];
	s1_trimmed[i] = '\0';
	return (s1_trimmed);
}
