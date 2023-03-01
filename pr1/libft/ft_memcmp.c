/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:15:59 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:41:16 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*ucs1;
	const unsigned char		*ucs2;

	i = 0;
	ucs1 = (const unsigned char *)s1;
	ucs2 = (const unsigned char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (i < n)
	{
		if (ucs1[i] != ucs2[i])
			return ((ucs1[i]) - (ucs2[i]));
		i++;
	}
	return (0);
}
