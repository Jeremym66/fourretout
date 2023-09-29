/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:27:19 by jmetezea          #+#    #+#             */
/*   Updated: 2023/02/14 15:34:06 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (!s2[0])
		return ((char *)s1);
	if (!len)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		if (ft_strncmp(s2, s1 + i, ft_strlen(s2)) == 0
			&& i + ft_strlen(s2) <= len)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
