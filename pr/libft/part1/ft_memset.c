/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:56:19 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/01 14:15:15 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	j;
	char			*str;

	str = (char *)b;
	i = 0;
	j = (unsigned char) c;
	while (i < len)
	{
		str[i] = j;
		i++;
	}
	return (b);
}
