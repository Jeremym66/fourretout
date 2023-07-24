/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/24 11:31:29 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//affiche la liste a supprimer avant le dernier push
void	ft_show_envp(t_data *data)
{
	int		i;
	t_envp	*show_envp;

	show_envp = data->envp;
	if (!show_envp)
		return ;
	i = 1;
	while (show_envp != NULL)
	{
		printf("nb %d : %s\n", i, show_envp->str);
		show_envp = show_envp->next;
		i++;
	}
}

void	ft_print_args(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_args[++i])
		ft_printf("d->args->cmd_args[%d] : %s \n", i, data->args->cmd_args[i]);
}

// attention si echo n'est pas dans "" il imprime tous les args suivants.
void	ft_echo(t_data *data)
{
	int	i;

	if (data->args->cmd_args[1] != NULL && ft_strcmp("<", data->args->cmd_args[1]) != 0)
	{
		if (ft_strcmp("-n", data->args->cmd_args[1]) == 0
			&& data->args->cmd_args[2] != NULL)
		{
			i = 1;
			while (data->args->cmd_args[++i] && data->next_pipe > i)
				ft_printf("%s", data->args->cmd_args[i]);
		}
		else if (ft_strcmp("-n", data->args->cmd_args[1]) == 0)
			return ;
		else
		{
			i = 0;
			while (data->args->cmd_args[++i] && data->next_pipe > i)
			{
				if (i == 1)
					ft_printf("%s", data->args->cmd_args[i]);
				else if (i > 1)
					ft_printf(" %s", data->args->cmd_args[i]);
			}
			ft_printf("\n");
		}
	}
	else
		ft_printf("\n");
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}
