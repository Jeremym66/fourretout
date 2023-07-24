/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:42:59 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/15 13:51:41 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_str_in_tab(char *s, char **tab)
{
	int	i;
	int	m;

	i = 0;
	while (tab[i])
	{
		m = max(l_egal(tab[i]), l_egal(s));
		if (!ft_strncmp(tab[i], s, m))
			return (1);
		i++;
	}
	return (0);
}

void	free_double_char(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

//permet d'afficher la liste chainee
void	ft_print_chain(t_lst *lst)
{
	int	max;

	max = 100;
	printf("chain:\n\n");
	while (lst && max)
	{
		printf("|%s|\n", lst->content);
		lst = lst->next;
		max--;
	}
}

//permet de free une liste chainee [t_lst]
void	ft_free_lst(t_lst *lst)
{
	t_lst	*next;

	while (lst)
	{
		free(lst->content);
		next = lst->next;
		free(lst);
		lst = next;
	}
}
