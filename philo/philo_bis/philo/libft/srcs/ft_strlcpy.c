/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:17:22 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/04 10:17:55 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cur;

	if (size == 0)
		return (ft_strlen(src));
	cur = 0;
	while (src[cur] && cur < (size - 1))
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = 0;
	return (ft_strlen(src));
}
