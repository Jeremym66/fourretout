/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:25:05 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 20:25:53 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;
	size_t	len_dest;

	if ((!dest || !src) && size == 0)
		return (0);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dest)
		return (size + len_src);
	while (src[i] && (i + len_dest) < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (len_src + len_dest);
}
