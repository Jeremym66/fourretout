/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/07/24 15:59:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_envp(t_data *data, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		add_str_endlst(data->envp, envp[i]);
}

void	reinit_minishell(t_data *data)
{
	//ft_free_args(data);
	ft_free_command_var(data);
}

void	init_minishell(t_data *data, char **envp)
{
	int	i;

	i = 0;
	data->envp = (t_envp *)malloc(sizeof(t_envp));
	data->args = (t_args *)malloc(sizeof(t_args));
	data->envp->next = NULL;
	data->envp->str = NULL;
	init_envp(data, envp);
	data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
	data->str_temp = NULL;
	data->str_temp2 = NULL;
	data->redirected = 0;
	data->piped = 0;
	data->next_pipe = 42;
	data->var = (t_command *)malloc(sizeof(t_command));
	while (i <= 99)
		data->var->commands[i++] = NULL;
	data->var->word = NULL;
	data->var->str = NULL;
	data->var->quote = NULL;
	free(data->var->word);
}
