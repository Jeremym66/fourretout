/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:57:31 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/10 09:08:32 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cur;

	src_len = ft_strlen(dst);
	cur = 0;
	if (dstsize <= src_len)
		return (ft_strlen(src) + dstsize);
	while (src[cur] && (src_len + cur) < (dstsize - 1))
	{
		dst[src_len + cur] = src[cur];
		cur++;
	}
	dst[src_len + cur] = 0;
	return (ft_strlen(src) + src_len);
}
