/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dobble_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:04:58 by kaly              #+#    #+#             */
/*   Updated: 2023/07/24 10:29:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dobble_and(t_data *data, char **envp)
{
	int	i; 

	i = -1;
	while (data->args->cmd_args[++i])
	{
		data->next_pipe = 0;
		if (ft_strncmp(data->args->cmd_args[i], "&&", 2) == 0)
		{
			data->next_pipe = i;
			if (find_builtin(data, envp) == 0)
				execute_command(data, envp);
			data->args->cmd_args = data->args->cmd_args + i + 1;
			i = -1;
		}
	}
	data->next_pipe = 42;
	if (find_builtin(data, envp) == 0)
		execute_command(data, envp);
	data->piped = 1;
}

void	ft_dolls_and(t_data *data, char **envp)
{
	data->piped = 1;
	if (!envp)
		return ;
	ft_printf("faut crerr la fonction $? \n");
}

void	ft_pipe(t_data *data, char **envp)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (find_builtin(data, envp) == 0)
			execute_command(data, envp);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		status = ((status & 0xFF00) >> 8);
	}
	data->piped = 1;
}
