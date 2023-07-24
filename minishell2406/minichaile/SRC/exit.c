/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:45:39 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/04 10:22:47 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exit(t_msh *msh, int status)
{
	int	j;

	if (msh->l)
		free(msh->l);
	if (msh->lvl)
		free(msh->lvl);
	j = 0;
	if (msh->cmd)
	{
		while (msh->cmd[j])
			free(msh->cmd[j++]);
		free(msh->cmd);
	}
	if (msh->parsed)
		ft_free_lst(msh->parsed);
	j = 0;
	while (msh->c_env[j])
		free(msh->c_env[j++]);
	free(msh->c_env);
	msh->status = status;
	exit(status);
}
