/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:22:01 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:02:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** The  memchr()  function  scans  the  initial n bytes of the memory area
** pointed to by s for the first instance of c.  Both c and the bytes of the
** memory area pointed to by s  are  interpreted as unsigned char.
**
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*strcopy;

	index = 0;
	strcopy = (unsigned char *)s;
	while (index < n)
	{
		if (strcopy[index] == (unsigned char)c)
			return ((void *)&strcopy[index]);
		index++;
	}
	return (NULL);
}
