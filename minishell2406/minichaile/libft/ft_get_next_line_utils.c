/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:32:43 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/24 14:21:35 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup_line(char *s, int d)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s[i])
		i++;
	ptr = (char *)malloc((i + 1 - d) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[d + i])
	{
		ptr[i] = s[d + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	strlen_line(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*strchr_line(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == 0)
		return ((char *)(s + i));
	return (NULL);
}

char	*strjoin_line(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((strlen_line(s1) + strlen_line(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		free(s1);
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}
