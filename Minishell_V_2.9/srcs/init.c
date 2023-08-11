/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/08/09 14:27:19 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_args(t_data *data)
{
	data->args = (t_args *)malloc(sizeof(t_args));
	data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
	data->args_start = 0;
	data->args_end = (int *)malloc(sizeof(int) * 100);
	data->args_end[0] = 0;
	data->args_max = 0;
}

void	init_envp(t_data *data, char **envp)
{
	int	i;

	i = -1;
	data->envp = (t_envp *)malloc(sizeof(t_envp));
	data->envp->next = NULL;
	data->envp->str = NULL;
	while (envp[++i])
		add_str_endlst(data->envp, envp[i]);
}

void	init_parse(t_data *data)
{
	data->var->i = 0;
	data->var->num_words = 0;
	if (data->var->word != NULL)
		ft_free_chars(data->var->word);
	if (data->var->str != NULL)
		ft_free_chars(data->var->str);
}

void	init_pipe(t_data *data)
{
	data->pipe = (t_pipe *)malloc(sizeof(t_pipe));
	data->pipe->nbr_of_pipe = 0;
	data->pipe->infile = dup(STDIN_FILENO);
	data->pipe->outfile = dup(STDOUT_FILENO);
	data->pipe->idx = 0;
	data->pipe->cmd_nbrs = 0;
}

void	init_var(t_data *data)
{
	int		i;

	i = 0;
	data->var = (t_var *)malloc(sizeof(t_var));
	while (i <= 99)
		data->var->commands[i++] = NULL;
	data->var->i = 0;
	data->var->num_words = 0;
	data->var->quote_type = 0;
	data->var->str = NULL;
	data->var->word = NULL;
}
