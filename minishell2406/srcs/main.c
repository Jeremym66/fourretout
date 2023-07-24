/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:09:36 by kaly              #+#    #+#             */
/*   Updated: 2023/07/24 16:33:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (ft_strlen(cmd) == 0)
		return (NULL);
	if (cmd)
	{
		while (*paths)
		{
			if (ft_cmp_paths(cmd, *paths) > 4)
				return (cmd);
			tmp = ft_strjoin(*paths, "/");
			command = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(command, 0) == 0)
				return (command);
			free(command);
			paths++;
		}
	}
	return (NULL);
}

void	get_readline(t_data *data)
{
	data->var->str = NULL;
	data->str_temp = NULL;
	free(data->var->str);
	free(data->str_temp);
	ft_printf("apres le free de get readline\n");
	ft_printf("data->str_temp : %s\n", data->str_temp);
	ft_printf("data->var->str : %s\n", data->var->str);
	if (data->piped != 49)
		data->str_temp = readline("~>$ ");
	else
	{
		data->str_temp = readline("");
		if (data->str_temp == NULL)
		{
			dup2(data->redirected2, STDIN_FILENO);
			close(data->redirected2);
			free(data->str_temp);
			data->str_temp = readline("~>$ ");
			data->piped = 0;
		}
	}
	if (!data->str_temp)
	{
		free(data->var->word);
		free(data->var);
		ft_printf("Minishell is closed.\nThat's the end of your life !\n");
		exit(EXIT_FAILURE);
	}
	add_history(data->str_temp);
}

void	shell_loop(t_data *data, char **envp)
{
	struct sigaction	act;
	int		i;

	ft_signal(&act, data);
	while (1)
	{
		//
		//data->str_temp = ft_get_next_line(0);
		//
		get_readline(data);
		parse(data);
		give_me_the_money(data);
		check_redirect(data, envp);
		data->next_pipe = 42;
		if (data->piped == 0)
			if (find_builtin(data, envp) == 0)
				execute_command(data, envp);
		if (data->redirected == 0)
			data->piped = 0;
		ft_printf("Minishell fin de loop avant\n");
		ft_print_args(data);
		//ft_show_envp(data);
		ft_printf("data->str_temp : %s\n", data->str_temp);
		ft_printf("data->str_temp2 : %s\n", data->str_temp2);
		i = -1;
		while (++i < (int)data->var->num_words)
			ft_printf("data->var->commands[%d] : %s\n", i, data->var->commands[i]);
		ft_free_cmd_args(data);
		//free(data->var->str);
		data->var->word = NULL;
		free(data->var->word);
		ft_printf("Minishell fin de loop apres\n");
		ft_print_args(data);
		//ft_show_envp(data);
		ft_printf("data->var->quote : %s\n", data->var->quote);
		ft_printf("data->var->str : %s\n", data->var->str);
		ft_printf("data->var->word : %s\n", data->var->word);
		ft_printf("data->str_temp : %s\n", data->str_temp);
		ft_printf("data->str_temp2 : %s\n", data->str_temp2);
		i = -1;
		while (++i < (int)data->var->num_words)
			ft_printf("data->var->commands[%d] : %s\n", i, data->var->commands[i]);
		

	}
}

int	find_builtin(t_data *data, char **envp)
{
	if (ft_strcmp("", data->str_temp) == 0)
	{
		
		shell_loop(data, envp);
	}
	if (ft_strcmp("exit", data->str_temp) == 0)
		ft_exit(data);
	else if (ft_strcmp("echo", data->args->cmd_args[0]) == 0)
		ft_echo(data);
	else if (ft_strcmp("cd", data->args->cmd_args[0]) == 0)
		ft_cd(data);
	else if (ft_strcmp("pwd", data->args->cmd_args[0]) == 0)
		ft_pwd();
	else if (ft_strcmp("export", data->args->cmd_args[0]) == 0)
		ft_export(data, data->args->cmd_args[1]);
	else if (ft_strcmp("unset", data->args->cmd_args[0]) == 0)
		ft_unset(data, data->args->cmd_args[1]);
	else if (ft_strcmp("env", data->args->cmd_args[0]) == 0)
		ft_show_envp(data);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = (t_data *)malloc(sizeof(t_data));
	init_minishell(data, envp);
	shell_loop(data, envp);
	return (0);
}
