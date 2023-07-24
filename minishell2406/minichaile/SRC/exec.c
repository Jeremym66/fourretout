/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:43:49 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/04 12:50:21 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execve(t_msh *msh, char *pathname)
{
	execve(pathname, msh->cmd, msh->c_env);
	ft_putstr_fd(msh->cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free(pathname);
}

void	fork_to_pipe(t_msh *msh)
{
	int	pid;
	int	status;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		close(fd[0]);
		if (msh->piped && !msh->redirected_out)
			dup2(fd[1], 1);
		msh_executer(msh);
		cmd_exit(msh, 127);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd[1]);
		if (msh->piped && !msh->redirected_in)
			dup2(fd[0], 0);
		else
			dup2(msh->std_in, 0);
		msh->status = ((status & 0xFF00) >> 8);
	}
}

void	cmd_exec(t_msh *msh)
{
	char	*pathname;

	if (!msh->cmd[0][0])
		return ;
	if (msh->cmd[0][0] == '.' && msh->cmd[0][1] == '/')
		pathname = find_exec_path(msh);
	else if (msh->cmd[0][0] == '/')
		pathname = find_exec_path(msh);
	else
		pathname = find_path(msh);
	if (!ft_strncmp(pathname, "No path", 7))
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(msh->cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		msh->status = 127;
		free(pathname);
		cmd_exit(msh, 127);
	}
	else
		ft_execve(msh, pathname);
}
