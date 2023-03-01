/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavaness <bavaness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:39:16 by bavaness          #+#    #+#             */
/*   Updated: 2023/02/28 20:23:48 by bavaness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	i;

	i = 0;
	new_s = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

int	gnl_have_nl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
	}
	while (s2[i2])
	{
		s[i + i2] = s2[i2];
		i2++;
	}
	s[i + i2] = '\0';
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
