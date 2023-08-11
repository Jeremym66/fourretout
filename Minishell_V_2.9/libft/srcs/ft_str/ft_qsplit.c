/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/22 10:49:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

typedef struct s_var
{
	char	*quote;
	char	*str;
	char	*next_space;
	char	*word;
	char	*words[100];
	size_t	num_words;
	size_t	i;
}				t_var;

void	add_word_to_string(int j, t_var *var)
{
	int	word_length;

	if (j == 0)
		word_length = var->quote - var->str - var->i - 1;
	else if (j == 1)
		word_length = var->next_space - var->str - var->i;
	else if (j == 2)
		word_length = (ft_strlen(var->str) - var->i);
	var->word = malloc(sizeof(char) * (word_length + 1));
	ft_strncpy(var->word, var->str + var->i, word_length);
	var->word[word_length] = '\0';
	var->words[(var->num_words)] = var->word;
	((var->num_words))++;
	if (j == 0)
		var->i += (var->quote - var->str - var->i);
	else if (j == 1)
		var->i += (var->next_space - var->str - var->i);
}

void	process_string(t_var *var)
{
	var->i = 0;
	while (var->i < ft_strlen(var->str))
	{
		if (var->str[var->i] == ' ' || var->str[var->i] == '\t'
			|| var->str[var->i] == '\n')
			continue ;
		else if (var->str[var->i] == '\'' || var->str[var->i] == '"')
		{
			var->quote = ft_strchr(var->str + var->i + 1, var->str[var->i]);
			if (var->quote != NULL)
				add_word_to_string(0, var);
		}
		else
		{
			var->next_space = ft_strchr(var->str + var->i + 1, ' ');
			if (var->next_space != NULL)
				add_word_to_string(1, var);
			else
			{
				add_word_to_string(2, var);
				break ;
			}
		}
		var->i++;
	}
}

char	**ft_qsplit(char *s)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var) + 1);
	var->num_words = 0;
	var->str = s;
	process_string(var);
	return (var->words);
}

/*void	free_string_info(t_var *var)
{
	var->i = 0;
	while (var->i < var->num_words)
	{
		free(var->words[var->i]);
		var->i++;
	}
}

void	print_string_info(t_var *var)
{
	var->i = 0;
	printf("Words:\n");
	while (var->i < var->num_words)
	{
		printf("  %ld: \"%s\"\n", var->i, var->words[var->i]);
		var->i++;
	}
}

int	main(void)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var) + 1);
	var->num_words = 0;
	var->str = "word1 && word2 | word3 'word4 with spaces'";
	process_string(var);
	print_string_info(var);
	free_string_info(var);
	return (0);
}*/
