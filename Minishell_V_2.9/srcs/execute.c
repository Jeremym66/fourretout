/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/10 14:25:02 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_cmd(t_data *d, char **envp)
{
	d->cmd_prompt = get_cmd(d->args->cmd_paths,
			d->args->cmd_args[d->args_start]);
	if (d->args->cmd_args[d->args_start + 1])
	{
		if (ft_strncmp("<", d->args->cmd_args[d->args_start + 1], 1) == 0)
		{
			if (ft_strncmp("<<", d->args->cmd_args[d->args_start + 1], 2)
				== 0)
				return ;
			d->args->cmd_args[d->args_start + 1]
				= d->args->cmd_args[d->args_start];
			d->args->cmd_args = d->args->cmd_args + 1;
		}
	}
	if (d->cmd_prompt != NULL)
		execve(d->cmd_prompt, d->args->cmd_args, envp);
	else
	{
		ft_printf("%s : commande introuvable\n",
			d->args->cmd_args[d->args_start]);
		exit(EXIT_FAILURE);
	}
}

void	exec_last2(t_data *d, char **envp)
{
	d->end = 1;
	check_exit(d);
	if (find_builtin_outside(d))
		return ;
	d->pid_last = fork();
	if (d->pid_last == -1)
		msg_error("fork exec_last doesn,t work.\n");
	else if (d->pid_last == 0)
	{
		check_redirect(d);
		find_builtin_inside(d);
		execute_cmd(d, envp);
	}
	else
	{
		dup2(d->pipe->outfile, STDOUT_FILENO);
		waitpid(d->pid_last, &d->error_number, 0);
		d->error_number *= 127;
	}
}

void	exec_last(t_data *d, char **envp)
{
	if (d->pid_pipe > 0)
	{
		kill(d->pid_pipe, SIGKILL);
		d->pid_pipe = 0;
	}
	if (d->pipe->nbr_of_pipe > 0)
	{
		d->args_start = d->args_end[0] + 2;
		d->args_end[0] = d->args_max;
	}
	if ((ft_strcmp("", d->original_prompt) == 0)
		|| ft_only_space(d->original_prompt) == 1)
	{
		if (ft_only_space(d->original_prompt) == 1)
		{
			free(d->original_prompt);
			d->original_prompt = NULL;
		}
		shell_loop(d, envp);
	}
	else
		exec_last2(d, envp);
}
