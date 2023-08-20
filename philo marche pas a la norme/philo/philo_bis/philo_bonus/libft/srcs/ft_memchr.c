/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:54:33 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/11 10:37:24 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				cur;
	unsigned char const	*data;

	cur = 0;
	data = (unsigned char const *)s;
	while (cur < n)
	{
		if (data[cur] == (unsigned char)c)
			return ((void *)(data + cur));
		cur++;
	}
	return (NULL);
}
