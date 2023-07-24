/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:00:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/24 10:30:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_cmd_args(t_data *data)
{
	int	i;

	i = -1;
	while (++i < (int)data->var->num_words)
	{
		data->args->cmd_args[i] = NULL;
		free(data->args->cmd_args[i]);
	}
}

void	ft_free_args(t_data *data)
{
	ft_free_cmd_args(data);
	free(data->args->cmd_args);
}

void	ft_free_paths(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_paths[++i])
		free(data->args->cmd_paths[i]);
	free(data->args->cmd_paths);
}

void	ft_free_str_temp(int i, t_data *data)
{
	if (i == 1)
		free(data->str_temp);
	else if (i == 2)
		free(data->str_temp2);
	else if (i == 3)
	{
		free(data->str_temp);
		free(data->str_temp2);
	}
}

void	ft_free_envp(t_data *data)
{
	t_data	*dup;

	dup = data;
	while (dup->envp)
	{
		free(data->envp->str);
		dup->envp = dup->envp->next;
		free(data->envp);
	}
	free(data->envp);
}

void	ft_free_command_var(t_data *data)
{
	int	i;

	free(data->var->quote);
	free(data->var->str);
	i = -1;
	while (++i == 99)
		free(data->var->commands[i]);
	free(data->var->commands[i]);
	free(data->var->word);
	free(data->var);
}

void	ft_free_all(int i, t_data *data)
{
	ft_free_envp(data);
	ft_free_str_temp(i, data);
	ft_free_args(data);
	ft_free_paths(data);
	free(data);
}
