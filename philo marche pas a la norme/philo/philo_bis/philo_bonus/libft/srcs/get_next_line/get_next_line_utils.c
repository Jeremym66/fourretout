/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:50:24 by ocartier          #+#    #+#             */
/*   Updated: 2022/01/31 15:04:51 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

void	shiftstr(char **str, size_t start)
{
	char	*tmp;

	tmp = *str;
	*str = ft_substr(*str, start, ft_strlen(*str));
	free(tmp);
}

long	charchr(const char *s, char c)
{
	long	cur;

	cur = 0;
	while (s[cur])
	{
		if (s[cur] == (unsigned char)c)
			return (cur);
		cur++;
	}
	if (s[cur] == (unsigned char)c)
		return (cur);
	return (-1);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	cur1;
	size_t	cur2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	cur1 = -1;
	while (s1[++cur1])
		result[cur1] = s1[cur1];
	cur2 = -1;
	while (s2[++cur2])
		result[cur1++] = s2[cur2];
	result[cur1] = '\0';
	free(s1);
	return (result);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
	}
	else
	{
		new_len = ft_strlen(s + start);
		if (!(new_len < len))
			new_len = len;
		sub = (char *)malloc((new_len + 1) * sizeof(char));
		if (!sub)
			return (NULL);
		sub[new_len] = 0;
		while (new_len-- > 0)
			sub[new_len] = s[start + new_len];
	}
	return (sub);
}
