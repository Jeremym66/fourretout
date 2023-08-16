/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:30:40 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/10 14:17:38 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cur;
	char	*d1;
	char	*d2;

	if (n == 0)
		return (0);
	cur = 0;
	d1 = (char *)s1;
	d2 = (char *)s2;
	while (n--)
	{
		if (d1[cur] != d2[cur])
			return ((unsigned char)d1[cur] - (unsigned char)d2[cur]);
		cur++;
	}
	return (0);
}
