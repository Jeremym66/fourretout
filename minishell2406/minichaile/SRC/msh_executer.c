/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:47:17 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/04 11:27:28 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(t_msh *msh)
{
	if (!msh->cmd[0])
		return (1);
	if (!ft_strncmp(msh->cmd[0], "pwd", 3))
		return (1);
	else if (!ft_strncmp(msh->cmd[0], "exit", 5))
		return (1);
	else if (!ft_strncmp(msh->cmd[0], "env", 4))
		return (1);
	else if (!ft_strncmp(msh->cmd[0], "unset", 6))
		return (1);
	else if (!ft_strncmp(msh->cmd[0], "export", 7))
		return (1);
	else if (!ft_strncmp(msh->cmd[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(msh->cmd[0], "echo", 5))
		return (1);
	else
		return (0);
}

void	msh_executer(t_msh *msh)
{
	if (!msh->cmd[0])
		return ;
	msh->status = 1;
	if (!ft_strncmp(msh->cmd[0], "pwd", 3))
		cmd_pwd(msh);
	else if (!ft_strncmp(msh->cmd[0], "exit", 5))
		cmd_exit(msh, 0);
	else if (!ft_strncmp(msh->cmd[0], "env", 4))
		cmd_env(msh);
	else if (!ft_strncmp(msh->cmd[0], "unset", 6))
		cmd_unset(msh);
	else if (!ft_strncmp(msh->cmd[0], "export", 7))
		cmd_export(msh);
	else if (!ft_strncmp(msh->cmd[0], "cd", 3))
		cmd_cd(msh);
	else if (!ft_strncmp(msh->cmd[0], "echo", 5))
		cmd_echo(msh);
	else
		cmd_exec(msh);
}
