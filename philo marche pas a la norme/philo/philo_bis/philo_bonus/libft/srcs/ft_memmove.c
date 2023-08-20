/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:12:17 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/11 09:33:58 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*data_dst;
	char	*data_src;

	if (!src && !dst)
		return (NULL);
	if (src > dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		data_dst = (char *)dst;
		data_src = (char *)src;
		while (len--)
			data_dst[len] = data_src[len];
	}
	return (dst);
}
