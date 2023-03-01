/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:12:01 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:38:10 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_src;
	size_t	dst_len;

	if (size == 0)
		return (size + ft_strlen(src));
	dst_len = ft_strlen((const char *)dst);
	if (dst_len > size)
		return (size + ft_strlen(src));
	i_src = 0;
	while (dst_len + i_src < size - 1 && src[i_src])
	{
		dst[dst_len + i_src] = src[i_src];
		i_src++;
	}
	dst[dst_len + i_src] = '\0';
	return (dst_len + ft_strlen(src));
}
