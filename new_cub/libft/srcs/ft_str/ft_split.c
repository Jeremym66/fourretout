/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:21:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/11 14:18:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** Alloue (avec malloc) et retourne un tableau de chaînes de caractères
** obtenu en séparant ’s’ à l’aide du caractère ’c’, utilisé comme délimiteur.
** Le tableau doit être terminé par NULL. Renvoie NULL si l'allocation échoue.
**
*/

static int	ft_spart_break(char const *s, char c)
{
	int	index;
	int	n_break;

	if (!s || !s[0])
		return (0);
	index = 0;
	n_break = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			n_break++;
			while (s[index] && s[index] != c)
				index++;
		}
	}
	return (n_break);
}

static char	**ft_ico_malloc_error(char **result, int index)
{
	int	index2;

	index2 = 0;
	while (index2 < index && result[index2])
	{
		free(result[index2]);
		index2++;
	}
	free(result);
	return (NULL);
}

static char	*ft_spart_cpy(char *spart, int sp_length, char const *s, int i)
{
	int	index_of_spart;

	index_of_spart = 0;
	while (index_of_spart < sp_length)
	{
		spart[index_of_spart] = s[i + index_of_spart];
		index_of_spart++;
	}
	spart[index_of_spart] = '\0';
	return (spart);
}

char	**ft_spart_malloc(char **res, int n_break, char const *s, char c)
{
	int	index_in_s;
	int	index_of_spart;
	int	last_index_in_s;
	int	sp_len;

	index_in_s = 0;
	index_of_spart = 0;
	sp_len = 0;
	while (s[index_in_s] && index_of_spart < n_break)
	{
		while (s[index_in_s] && s[index_in_s] == c)
			index_in_s++;
		last_index_in_s = index_in_s;
		while (s[index_in_s] && s[index_in_s++] != c)
			sp_len++;
		res[index_of_spart] = (char *)malloc(sizeof(char) * (sp_len + 1));
		if (res[index_of_spart] == NULL)
			return (ft_ico_malloc_error(res, index_of_spart));
		ft_spart_cpy(res[index_of_spart], sp_len, s, last_index_in_s);
		sp_len = 0;
		index_of_spart++;
	}
	res[index_of_spart] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n_break;

	if (s == NULL)
		return (NULL);
	n_break = ft_spart_break(s, c);
	result = (char **)malloc(sizeof(char *) * (n_break + 1));
	if (result == NULL)
		return (NULL);
	result[n_break] = NULL;
	ft_spart_malloc(result, n_break, s, c);
	return (result);
}
