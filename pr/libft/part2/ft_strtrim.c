/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:02:54 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/01 11:23:53 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *sep)
{
	size_t	i;
	char	*res;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s || !sep)
		return (NULL);
	j = ft_strlen(s);
	if (ft_strlen(sep) == 0 || j == 0)
		return (ft_strdup((char *)s));
	while (s[i] && ft_strchr(sep, (int)s[i]) != 0)
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (j >= 1 && (ft_strchr(sep, (int)s[j])) != 0)
		j--;
	res = (char *)ft_calloc(j - i + 2, sizeof(char));
	if (!res)
		return (NULL);
	while (i <= j)
		res[k++] = s[i++];
	res[k] = '\0';
	return (res);
}
