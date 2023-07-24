/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:30:00 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/02 15:32:31 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//initialise un nouver objet [t_lst]
t_lst	*ft_init_lst(char *str, t_lst *first, t_lst *nextof)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	new->content = str;
	new->first = first;
	new->next = NULL;
	if (nextof)
	{
		new->next = nextof->next;
		nextof->next = new;
	}
	return (new);
}

//permet de recuperer une chaine a partir d'une quote jusqu'a la meme quote
char	*ft_strchar(char *str, int *i)
{
	char	*res;
	char	c;
	int		j;

	c = str[*i];
	j = 1;
	while (str[*i + j] && str[*i + j] != c)
		j++;
	res = malloc(j + 3);
	res[0] = c;
	j = 1;
	while (str[*i + j] != c && str[*i + j])
	{
		res[j] = str[*i + j];
		j++;
	}
	res[j] = c;
	j++;
	*i += j;
	res[j] = 0;
	return (res);
}

//renvoie une chaine de caracteres ouverte et fermee par le meme type de quote
//	ou une chaine n'en contenant aucune
char	*ft_get_str(char *str, int *i)
{
	char	*res;
	int		j;

	j = 0;
	if (!str[*i])
		return (NULL);
	if (str[*i] == 34 || str[*i] == 39)
		return (ft_strchar(str, i));
	while (str[*i + j] != 34 && str[*i + j] != 39 && str[*i + j])
		j++;
	res = malloc(j + 1);
	j = 0;
	while (str[*i + j] != 34 && str[*i + j] != 39 && str[*i + j])
	{
		res[j] = str[*i + j];
		j++;
	}
	*i += j;
	res[j] = 0;
	return (res);
}

//effectue la 1ere partie du parse avec la creation de la liste et application
//	du 1er filtre
t_lst	*ft_first_parse(char *str)
{
	t_lst	*new;
	t_lst	*first;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_get_str(str, &i);
	new = ft_init_lst(tmp, NULL, NULL);
	first = new;
	first->first = first;
	while (1)
	{
		tmp = ft_get_str(str, &i);
		if (!tmp)
			break ;
		new = ft_init_lst(tmp, first, new);
	}
	return (first);
}

//centre de commandes du parse
t_lst	*ft_parse(char *str, t_msh *msh)
{
	t_lst	*new;

	(void)msh;
	new = ft_init_lst(ft_strdup(str), NULL, NULL);
	new->first = new;
	ft_space_parse(new);
	ft_split_parse(new);
	ft_rm_spaces(new);
	return (new);
}

//main temporaire a commenter

/*
int	main(int argc, char **argv)
{
	t_lst	*lst;

	lst = ft_parse(argv[1], NULL);
	ft_print_chain(lst);
	ft_free_lst(lst);
	return (0);
}
*/

//"saluuut 'comment                        vas \"tu??' chepo \"\"ecoute..."
