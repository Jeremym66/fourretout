/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:27:53 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/04 11:40:53 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_parser(t_msh *msh)
{
	int		i;
	t_lst	*parsed;

	i = 0;
	parsed = msh->parsed;
	msh->cmd = malloc(sizeof(char *) * (ft_length_lst(parsed) + 1));
	while (parsed)
	{
		msh->cmd[i] = ft_strdup(parsed->content);
		i++;
		parsed = parsed->next;
	}
	msh->cmd[i] = 0;
}

void	nullisation(t_msh *msh)
{
	msh->l = NULL;
	msh->cmd = NULL;
	msh->parsed = NULL;
	cmd_exit(msh, 1);
}

void	get_l(t_msh *msh)
{
	char	*tmp;

	if (msh->gnl)
	{
		ft_printf("~/GNL/> ");
		tmp = get_next_line(0);
		if (!tmp)
			nullisation(msh);
		msh->l = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
	}
	else
	{
		msh->l = readline("~/>");
		if (!msh->l)
			nullisation(msh);
		add_history(msh->l);
	}
}

void	minishell(t_msh *msh)
{
	struct sigaction	act;

	ft_signal(&act, msh);
	while (1)
	{
		get_l(msh);
		ft_cmd(msh, ft_parse(msh->l, msh));
		free(msh->l);
		msh->l = 0;
		ft_free_lst(msh->parsed);
	}
}
