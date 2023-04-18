/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:16:08 by jmetezea          #+#    #+#             */
/*   Updated: 2023/02/13 17:23:37 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsrc;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ucsrc = (unsigned char *)src;
	ucdest = (unsigned char *)dest;
	if (dest <= src)
	{
		while (i < n)
		{
			ucdest[i] = ucsrc[i];
			i++;
		}
	}
	else
		while (n--)
			ucdest[n] = ucsrc[n];
	return (dest);
}
