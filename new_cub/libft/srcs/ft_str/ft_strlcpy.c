/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:26:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/04 15:38:20 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** The strlcpy functions copy strings. It are designed to be safer, more
** consistent, and less error prone replacements for strncpy. Unlike this
** function, strlcpy take the full size of the buffer (not just the length) and
** guarantee to NUL-terminate the result (as long as size is larger than 0.
** Note that a byte for the NUL should be included in size.
** Also note that strlcpy only operate on true ''C'' strings. This means src
** must be NUL-terminated.
** The strlcpy function copies up to size - 1 characters from the NUL-
** terminated string src to dest, NUL-terminating the result. 
**
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
