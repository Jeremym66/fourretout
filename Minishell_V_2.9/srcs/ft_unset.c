/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/08 15:42:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delete_arg_envp(t_data *data, char *args)
{
	t_envp	*delete;
	t_envp	*temp;

	delete = data->envp;
	if (ft_strncmp(args, delete->str, ft_strlen(args)) == 0)
	{
		temp = delete;
		data->envp = delete->next;
	}
	else
	{
		while (ft_strncmp(args, delete->next->str, ft_strlen(args)) != 0)
			delete = delete->next;
		temp = delete->next;
		delete->next = delete->next->next;
	}
	free(temp->str);
	free(temp);
}

void	ft_unset(t_data *data, char *args)
{
	int		a;
	t_envp	*list;

	a = 0;
	list = data->envp;
	while (list && a == 0)
	{
		if ((ft_strncmp(args, list->str, ft_strlen(args)) == 0))
		{
			ft_delete_arg_envp(data, args);
			a = 1;
			break ;
		}
		list = list->next;
	}
	if (ft_strncmp(args, "OLDPWD=", 7) == 0)
		a = 1;
	if (a == 0)
		ft_printf("la variable %s n'existe pas dans l'environnement\n", args);
	if (ft_strncmp(data->args->cmd_args[data->args_start + 1], "PATH", 4) == 0)
		data->args->cmd_paths = ft_split(find_path("PATH", data->envp), ':');
}
