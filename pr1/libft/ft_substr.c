/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:24:17 by aramon            #+#    #+#             */
/*   Updated: 2023/02/18 18:30:11 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*n;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		n = (char *)ft_calloc(ft_strlen(s + start) + 1, sizeof(char));
	else
		n = (char *)ft_calloc(len + 1, sizeof(char));
	if (n == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			n[j] = s[i];
			j++;
		}
		i++;
	}
	return (n);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = ft_substr("tripouille", 1, 1);
	printf("%s", s);
	return(0);
}*/
