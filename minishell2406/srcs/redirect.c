/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:49:01 by nours42           #+#    #+#             */
/*   Updated: 2023/07/24 16:17:13 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_simple_left(t_data *data, char **envp, int i)
{
	int		fd;
	int		stdin_fd;

	fd = open(data->args->cmd_args[i + 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(data->args->cmd_args[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	stdin_fd = dup(STDIN_FILENO);
	dup2(stdin_fd, STDIN_FILENO);
	data->next_pipe = i;
	if (find_builtin(data, envp) == 0)
		execute_command(data, envp);
	close(fd);
	close(stdin_fd);
	data->piped = 1;
	data->fd_redirect_in = 1;
}

void	redirect_dobble_left(t_data *data, char **envp, int i)
{
	int		fd;
	int		stdin_fd;
	char	*tmp;

	fd = open("make.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp = ft_get_next_line(0);
	if (!tmp || !envp)
		return ;
	while (strncmp(data->args->cmd_args[i + 1], tmp,
		ft_strlen(data->args->cmd_args[i + 1]))
		|| (ft_strlen(tmp) -1) > ft_strlen(data->args->cmd_args[i + 1]))
	{
		ft_putstr_fd(tmp, fd);
		free(tmp);
		tmp = ft_get_next_line(0);
	}
	free(tmp);
	close(fd);
	fd = open("make.tmp", O_RDONLY);
	stdin_fd = dup(STDIN_FILENO);
	data->piped = 49;
	data->redirected = fd;
	data->redirected2 = stdin_fd;
	data->next_pipe = i;
	data->fd_redirect_in = 1;
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	redirect_simple_right(t_data *data, char **envp, int i)
{
	int	fd;
	int	stdout_fd; 

	if (data->args->cmd_args[i + 1] == NULL)
		msg_error("bash: erreur de syntaxeeeeeeeee\n");
	fd = open(data->args->cmd_args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_printf("le fichier : %s a ete creeeeee\n", data->args->cmd_args[i + 1]);
	stdout_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	data->next_pipe = i;
	if (find_builtin(data, envp) == 0)
		execute_command(data, envp);
	dup2(stdout_fd, STDOUT_FILENO);
	close(stdout_fd);
	close(fd);
	data->piped = 1;
}

void	redirect_dobble_right(t_data *data, char **envp, int i)
{
	int	fd;
	int	stdout_fd; 

	fd = open(data->args->cmd_args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	ft_printf("le fichier : %s a ete cree\n", data->args->cmd_args[i + 1]);
	stdout_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	data->next_pipe = i;
	if (find_builtin(data, envp) == 0)
		execute_command(data, envp);
	//data->args->cmd_args = data->args->cmd_args + i + 1;
	dup2(stdout_fd, STDOUT_FILENO);
	close(stdout_fd);
	close(fd);
	data->piped = 1;
}
