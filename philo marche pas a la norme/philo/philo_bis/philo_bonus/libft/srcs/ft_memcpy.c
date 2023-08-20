/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:16:52 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/10 14:24:45 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur;
	char	*dst_data;
	char	*src_data;

	if (!src && !dst)
		return (NULL);
	cur = 0;
	dst_data = (char *)dst;
	src_data = (char *)src;
	while (cur < n)
	{
		dst_data[cur] = src_data[cur];
		cur++;
	}
	return (dst_data);
}
