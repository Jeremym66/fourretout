/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:24:28 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:43:13 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*get_word(const char *s, int *curr_i, char c)
{
	int		i;
	int		word_len;
	char	*word;

	i = *curr_i;
	while (s[i] && s[i] != c)
		i++;
	word_len = (i - *curr_i);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < word_len)
		word[i] = s[*curr_i + i];
	word[i] = '\0';
	*curr_i += i;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		k;
	int		word_count;
	char	**split;

	i = 0;
	word_count = count_word(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	k = 0;
	while (k < word_count)
	{
		split[k++] = get_word(s, &i, c);
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	split[k] = 0;
	return (split);
}
