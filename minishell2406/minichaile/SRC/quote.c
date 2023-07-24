/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:28:44 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/04 14:31:09 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_low_lines(char *str, int i, int *k)
{
	int	j;

	j = i;
	*k = -1;
	while (str[j] && !ft_is_in("\'\"", str[j]) && !ft_iswhitespace(str[j]))
		j++;
	return (j);
}

char	*ft_arg(char *str, int i, char **strr, t_msh *msh)
{
	char	*cat;
	char	*new;
	int		j;
	int		k;

	j = ft_low_lines(str, i, &k);
	if (str[j])
		cat = ft_get_cat(strr, str, i, j - i - 1);
	else
		cat = ft_get_cat(strr, str, i, j - i);
	if (!cat)
		cat = ft_itoa(msh->status);
	new = malloc(ft_strlen(str) - (j - i) + ft_strlen(cat) + 1);
	if (!new)
		return (str);
	while (++k < i)
		new[k] = str[k];
	i = 0;
	ft_append(new, cat, &k, &i);
	ft_append(new, str, &k, &j);
	new[k] = 0;
	free(str);
	free(cat);
	return (new);
}

char	*ft_clean(char *str)
{
	char	*res;
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 0;
	res = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		if (ft_is_in("\'\"", str[i]) && !c)
			c = str[i];
		else if (ft_is_in("\'\"", str[i]) && c == str[i])
			c = 0;
		else
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = 0;
	free(str);
	return (res);
}

void	ft_clean_quotes(t_lst *lst)
{
	while (lst && !ft_is_in("|", lst->content[0]))
	{
		if (ft_is_in(lst->content, '\'') || ft_is_in(lst->content, '\"'))
			lst->content = ft_clean(lst->content);
		lst = lst->next;
	}
}

void	ft_dquotes(t_msh *msh, t_lst *lst)
{
	int		i;
	t_lst	*first;

	first = lst;
	while (lst && lst->content[0] != '|')
	{
		i = 0;
		while (lst->content[i])
		{
			if (!(ft_im_in("\'\"", lst->content, i) == '\'')
				&& lst->content[i] == '$')
			{
				lst->content = ft_arg(lst->content, i, msh->c_env, msh);
				i = -1;
			}
			i++;
		}
		lst = lst->next;
	}
	ft_clean_quotes(first);
}
