/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:28:00 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/04 14:14:11 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//retire lst->next de la liste
void	ft_rm_mid(t_lst *lst)
{
	t_lst	*rm;

	rm = lst->next;
	lst->next = lst->next->next;
	free(rm->content);
	free(rm);
}

//renvoie c si src[i] est entre 2 caracteres identiques presents dans str
//exemple: si str = "\'\"", src = yoyo "heyhey", et i = 7 (e), retourne (int)'"'
int	ft_im_in(char *str, char *src, int i)
{
	char	c;
	int		j;

	j = 0;
	c = 0;
	while (src[j] && j < i)
	{
		if (ft_is_in(str, src[j]))
		{
			if (src[j] == c)
				c = 0;
			else if (!c)
				c = src[j];
		}
		j++;
	}
	return (c);
}

//recupere s1 jusqu'au 1er caractere etant present dans s2
char	*ft_split_part_1(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((s1[j] && !ft_is_in(s2, s1[j])) || (ft_im_in("'\"", s1, j) && s1[j]))
		j++;
	if (!j)
		j = 1;
	new = malloc(j + 1);
	while (i < j)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

//recupere s1 a partir du 1er caractere contenu dans s2
char	*ft_split_part_2(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((s1[j] && !ft_is_in(s2, s1[j])) || (ft_im_in("\'\"", s1, j) && s1[j]))
		j++;
	if (!j)
		j = 1;
	new = malloc((ft_strlen(s1) - j) + 1);
	while (s1[i + j])
	{
		new[i] = s1[i + j];
		i++;
	}
	new[i] = 0;
	return (new);
}

//split final

void	ft_split_parse(t_lst *lst)
{
	t_lst	*new;
	char	*str;
	int		i;

	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (ft_is_in("<>|& ", lst->content[i]) && !ft_im_in("\'\"",
					lst->content, i))
			{
				str = lst->content;
				new = ft_init_lst(ft_split_part_2(str, "<>|& "),
						lst->first, lst);
				lst->content = ft_split_part_1(str, "<>|& ");
				free(str);
				i = -1;
			}
			if (++i == 0)
				break ;
		}
		lst = lst->next;
		(void)new;
	}
}
