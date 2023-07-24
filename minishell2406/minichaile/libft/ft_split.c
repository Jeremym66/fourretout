/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:28:46 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/09 12:36:15 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_mots(char const *s, char c)
{
	int	nbr;
	int	i;
	int	etat;

	nbr = 0;
	i = 0;
	etat = 0;
	while (s[i])
	{
		if (etat == 0 && s[i] != c)
		{
			nbr++;
			etat = 1;
		}
		else if (s[i] == c)
			etat = 0;
		i++;
	}
	return (nbr);
}

static int	len(char const *s, char c, int pos)
{
	int	len;

	len = 0;
	while (s[pos] && s[pos] != c)
	{
		len++;
		pos++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		mots;
	int		j;
	char	**res;

	i = 0;
	mots = 0;
	res = malloc((nbr_mots(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (mots < nbr_mots(s, c))
	{
		j = 0;
		if (s[i] != c)
		{
			res[mots] = malloc((len(s, c, i) + 1) * sizeof(char));
			while (s[i] && s[i] != c)
				res[mots][j++] = s[i++];
			res[mots][j] = 0;
			mots++;
		}
		i++;
	}
	res[mots] = NULL;
	return (res);
}
