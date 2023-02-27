/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:55:33 by maserrie          #+#    #+#             */
/*   Updated: 2023/01/15 12:46:14 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len > 0)
	{
		((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
		len--;
	}
	return (dst);
}
