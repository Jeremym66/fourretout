/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:34:56 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/01 13:33:54 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	if ((!str || !to_find) && n == 0)
		return ((char *)str);
	len = ft_strlen(to_find);
	if (len == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j])
		{
			if (j == len - 1 && i + j < n)
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (0);
}
