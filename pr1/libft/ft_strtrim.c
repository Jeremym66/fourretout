/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:54:01 by aramon            #+#    #+#             */
/*   Updated: 2023/02/18 18:43:06 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_size_front(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	size;
	int	tmp;

	i = 0;
	size = 0;
	while (s1[i])
	{
		j = -1;
		tmp = 0;
		while (set[++j])
			if (s1[i] == set[j])
				tmp++;
		if (tmp > 0)
			size++;
		else
			return (size);
		i++;
	}
	return (size);
}

static	int	check_size_back(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	size;
	int	tmp;

	i = (int)ft_strlen(s1) - 1;
	size = 0;
	while (s1[i])
	{
		j = -1;
		tmp = 0;
		while (set[++j])
			if (s1[i] == set[j])
				tmp++;
		if (tmp > 0)
			size++;
		else
			return (size);
		i--;
	}
	return (size);
}

char	*apply_trim(const char *s1, char *trim, int f, int b)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i])
	{
		if (i >= f && i < b)
		{
			trim[k] = s1[i];
			k++;
		}
		i++;
	}
	return (trim);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	int		front;
	int		back;

	front = check_size_front(s1, set);
	if (front < (int)ft_strlen(s1))
		back = check_size_back(s1, set);
	else
		back = 0;
	trim = (char *)malloc(sizeof(char) * (ft_strlen(s1) - front - back + 1));
	if (!trim)
		return (NULL);
	trim = apply_trim(s1, trim, front, ft_strlen(s1) - back);
	trim[ft_strlen(s1) - back - front] = '\0';
	return (trim);
}
