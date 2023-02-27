/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:50:19 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/07 16:56:24 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	llen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	llen = ft_strlen(s + start);
	if (len < llen)
		llen = len;
	str = (char *) ft_calloc(llen + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < llen)
		str[i] = s[start + i];
	return (str);
}
