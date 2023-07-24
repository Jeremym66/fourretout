/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:13:10 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/04 14:31:11 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//renvoie 1 si c est un whitespace, 0 sinon
int	ft_iswhitespace(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

//renvoie 1 si str contient c, 0 sinon
int	ft_is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_cat_2(char **strr, char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (strr[i])
	{
		if (ft_strnstr(strr[i], str, ft_strlen(str)))
		{
			res = ft_strdup(ft_strchr(strr[i], '=') + 1);
			break ;
		}
		i++;
	}
	free(str);
	return (res);
}

char	*ft_get_cat(char **strr, char *str, int i, int n)
{
	int		j;
	char	*tmp;
	char	*res;

	j = 0;
	i++;
	if (str[i] == '?')
		return (NULL);
	tmp = malloc(n + 2);
	while (str[i + j] && j < n)
	{
		tmp[j] = str[i + j];
		j++;
	}
	tmp[j++] = '=';
	tmp[j] = 0;
	if (!is_str_in_tab(tmp, strr))
	{
		res = malloc(1);
		res[0] = 0;
		return (free(tmp), res);
	}
	return (ft_get_cat_2(strr, tmp));
}

void	ft_append(char *s1, char *s2, int *i, int *j)
{
	while (s2[*j])
		s1[(*i)++] = s2[(*j)++];
}
