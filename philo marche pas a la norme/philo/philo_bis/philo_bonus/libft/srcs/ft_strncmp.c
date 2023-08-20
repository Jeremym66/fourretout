/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:43:33 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/10 09:09:20 by ocartier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cur;

	if (n == 0)
		return (0);
	cur = 0;
	while (s1[cur] && s2[cur])
	{
		if (s1[cur] != s2[cur] || cur >= n - 1)
			return ((unsigned char)s1[cur] - (unsigned char)s2[cur]);
		cur++;
	}
	return ((unsigned char)s1[cur] - (unsigned char)s2[cur]);
}
