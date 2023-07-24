/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:29:20 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/04 14:13:25 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//taille de la liste chainee
int	ft_length_lst(t_lst *lst)
{
	int	i;

	i = 0 ;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	useless_but_useful(t_lst *lst, int *i, int *j, char *str)
{
	str[*i] = lst->content[*j];
	(*j)++;
	(*i)++;
}

//partie de ft_space_parse (25 lignes)
void	ft_space_parse_2(t_lst *lst, int *i, int *j, char *str)
{
	static char	in = 0;

	if (lst->content[*j] == 34 || lst->content[*j] == 39)
	{
		if (!in)
			in = lst->content[*j];
		else if (in == lst->content[*j])
			in = 0;
	}
	if (ft_iswhitespace(lst->content[*j]) && !in)
	{
		while (ft_iswhitespace(lst->content[*j]) && !in)
			(*j)++;
		if (*i && lst->content[*j])
		{
			str[*i] = ' ';
			(*i)++;
		}
	}
	else
		useless_but_useful(lst, i, j, str);
	if (!lst->content[*i])
		in = 0;
}

//remplace tous les whitespace n'etant pas entre quotes par des espaces
void	ft_space_parse(t_lst *lst)
{
	int		i;
	int		j;
	char	*str;

	while (lst)
	{
		i = 0;
		j = 0;
		str = malloc(ft_strlen(lst->content) + 1);
		while (lst->content[j])
			ft_space_parse_2(lst, &i, &j, str);
		str[i] = 0;
		free(lst->content);
		lst->content = str;
		lst = lst->next;
	}
}

//retire les espaces inutiles
void	ft_rm_spaces(t_lst *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		if (lst->next->content[0] == ' ' || !lst->next->content[0])
			ft_rm_mid(lst);
		lst = lst->next;
	}
}
