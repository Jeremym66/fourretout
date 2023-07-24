/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:15:41 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/03 17:09:30 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lenght_cmd(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst && lst->content[0] != '|')
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_lst	*end_cmd(t_msh *msh, t_lst *lst)
{
	int	i;

	i = 0;
	msh->cmd = malloc(sizeof(char *) * (lenght_cmd(lst) + 1));
	while (lst && lst->content[0] != '|')
	{
		msh->cmd[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	if (lst && lst->content[0] == '|')
		msh->piped = 1;
	msh->cmd[i] = 0;
	return (lst);
}

void	ft_cmd2(t_msh *msh, t_lst *parsed)
{
	msh->piped = 0;
	msh->redirected_in = 0;
	msh->redirected_out = 0;
	ft_dquotes(msh, parsed);
}

void	ft_cmd(t_msh *msh, t_lst *parsed)
{
	int	e;

	msh->parsed = parsed;
	while (parsed)
	{
		ft_cmd2(msh, parsed);
		parsed = end_cmd(msh, parsed);
		e = redirect_sort(msh);
		if (!msh->piped && builtin(msh) && !e)
			msh_executer(msh);
		if (!msh->piped && builtin(msh) && !e)
			dup2(msh->std_in, 0);
		else if (!e)
			fork_to_pipe(msh);
		free_double_char(msh->cmd);
		if (parsed && parsed->content[0] == '|')
			parsed = parsed->next;
		if (!msh->piped || msh->redirected_in || msh->redirected_out)
		{
			dup2(msh->std_out, 1);
			dup2(msh->std_in, 0);
		}
		unlink("make.tmp");
	}
}
