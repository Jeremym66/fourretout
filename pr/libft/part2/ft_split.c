/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:15:19 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/02 05:29:42 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_split2(char *str, size_t cpt, size_t len)
{
	char	**tab;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	tab = (char **)malloc((cpt + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (c < cpt)
	{
		while (!str[i] && i < len)
			i++;
		tab[c] = ft_strdup(str + i);
		if (!tab[c])
		{
			ft_free_tab(tab);
			return (NULL);
		}
		while (str[i])
			i++;
		c++;
	}
	tab[c] = 0;
	return (tab);
}

static char	**ft_transformation(char *str, char c, size_t len)
{
	size_t	i;
	size_t	cpt;
	int		test;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		test = 0;
		while (str[i] == c)
			str[i++] = 0;
		while (str[i] && str[i] != c)
		{
			i++;
			test = 1;
		}
		if (test)
			cpt++;
	}
	return (ft_split2(str, cpt, len));
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**tab;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	tab = ft_transformation(str, c, ft_strlen(s));
	free(str);
	return (tab);
}
