/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:58:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/10 16:11:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	how_many_pipe(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (d->args->cmd_args[++i])
	{
		if (ft_strcmp("|", d->args->cmd_args[i]) == 0)
		{
			d->args_end[j++] = i - 1;
			d->pipe->nbr_of_pipe++;
		}
	}
	d->args_end[j] = i - 1;
	d->args_max = d->args_end[j];
	i = -1;
	while (++i < d->pipe->nbr_of_pipe)
		d->pipe->pipe_fd[i] = -1;
}

void	execute_pipes(t_data *d, char **envp)
{
	if (d->pid_pipe > 0)
	{
		close(d->pipe->pipe_fd[0]);
		close(d->pipe->pipe_fd[1]);
		kill(d->pid_pipe, SIGKILL);
	}
	if (pipe(d->pipe->pipe_fd) == -1)
	{
		close(d->pipe->pipe_fd[0]);
		close(d->pipe->pipe_fd[1]);
		msg_error("le pipe ne s'est pas lancé ou n'a pas fonctionné.\n");
	}
	if (ft_strcmp("", d->original_prompt) == 0)
		shell_loop(d, envp);
	if (ft_strcmp("exit", d->original_prompt) == 0)
		ft_exit(d);
	else if (ft_strcmp("export", d->args->cmd_args[d->args_start]) == 0)
		ft_export(d, d->args->cmd_args[d->args_start + 1]);
	else if (ft_strcmp("unset", d->args->cmd_args[d->args_start]) == 0)
		ft_unset(d, d->args->cmd_args[d->args_start + 1]);
	else
		execute_pipe2(d, envp);
}

void	execute_pipe2(t_data *d, char **envp)
{
	check_exit(d);
	if (find_builtin_outside(d))
		return ;
	d->pid_pipe = fork();
	if (d->pid_pipe == -1)
	{
		close(d->pipe->pipe_fd[0]);
		close(d->pipe->pipe_fd[1]);
		msg_error("Fork on execute_pipe doesn't work.\n");
	}
	else if (d->pid_pipe == 0)
	{
		dup2(d->pipe->pipe_fd[1], STDOUT_FILENO);
		close(d->pipe->pipe_fd[0]);
		check_redirect(d);
		find_builtin_inside(d);
		execute_cmd(d, envp);
	}
	else
	{
		waitpid(d->pid_pipe, &d->error_number, 0);
		d->error_number *= 127;
		dup2(d->pipe->pipe_fd[0], STDIN_FILENO);
		close(d->pipe->pipe_fd[1]);
	}
}
