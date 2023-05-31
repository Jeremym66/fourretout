/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:30:51 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/31 15:51:56 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_count_word(char *str)
{
	int	i;
	int	word;
	
	word = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			else
				break ;
		}
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
			else
				break ;
		}
		word++;
	}
	return (word);
}
char	*ft_join(char *str, int start, int end)
{
	char	*word;
	int	i;

	word = malloc(sizeof(char) * end - start + 1);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	*ft_join_word(char *str, char **split, int count)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (k < count)
	{
		i = j;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		j = i;
		while (str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
			j++;
		split[k] = ft_join(str, i, j);
		k++;
	}
}

char	**ft_split(char *str)
{
	char	**split;
	int	word;
	int	i;

	word = ft_count_word(str);
	if (word == 0)
	{
		split = malloc(1);
		split[0] = NULL;
		return (split);
	}
	split = malloc(sizeof(char *) * word + 1);
	ft_join_word(str, split, word);
	return (split);
}

/*int	main(int ac, char **av)
{
	char	**test;
	int	i;

	if (ac == 2)
		test = ft_split(av[1]);
	i = 0;
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
}*/
