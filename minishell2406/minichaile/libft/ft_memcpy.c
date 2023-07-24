/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:04:56 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/16 12:57:29 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tempd;
	char	*temps;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tempd = (char *)dest;
	temps = (char *)src;
	while (i < n)
	{
		tempd[i] = temps[i];
		i++;
	}
	return (dest);
}
