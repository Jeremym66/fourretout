/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:16:18 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/09 16:36:31 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		i;
	int		fin;

	fin = ft_strlen(s1);
	start = 0;
	i = 0;
	while (check(s1[start], set))
		start++;
	while (check(s1[fin - 1], set) && fin > start)
			fin--;
	res = malloc(((fin - start) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (start < fin)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
