/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:44:31 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:40:59 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	if (dst > src)
	{
		while ((int)--n >= 0)
			d[n] = s[n];
	}
	else
	{
		i = -1;
		while (++i < n)
			d[i] = s[i];
	}
	return ((void *)d);
}
