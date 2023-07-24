/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/24 16:26:29 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_command(t_data *data, char **envp)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		data->str_temp2 = get_cmd(data->args->cmd_paths,
			data->args->cmd_args[0]);
		ft_printf("test1 : %s\n", data->str_temp2);
		if (data->args->cmd_args[1])
			if (ft_strncmp("<", data->args->cmd_args[1], 1) == 0)
			{
				ft_printf("test2\n");
				if(ft_strncmp("<<", data->args->cmd_args[1], 2) == 0)
					return ;
				data->args->cmd_args[1] = data->args->cmd_args[0];
				data->args->cmd_args = data->args->cmd_args + 1;
			}
		ft_printf("test3 : %s\n", data->str_temp2);
		if (data->str_temp2 != NULL)
		{
			execve(data->str_temp2, data->args->cmd_args, envp);
			free(data->str_temp2);
		}
		else if (ft_strcmp(data->args->cmd_args[0], "") == 0)
			exit(EXIT_FAILURE);
		else
		{
			ft_printf("%s : commande introuvable\n", data->args->cmd_args[0]);
			free(data->args->cmd_args[0]);
			exit(EXIT_FAILURE);
		}
		perror("Erreur d'exécution de la commande\n");
		exit(EXIT_FAILURE);
	}
	else if (data->pid < 0)
		perror("Erreur lors de la création du processus\n");
	else
		wait(NULL);	
}
