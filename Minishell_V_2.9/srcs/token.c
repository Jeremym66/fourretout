/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/01 17:57:46 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

		// else if (ft_strcmp("$?", data->args->cmd_args[i]) == 0)
		// 	ft_dolls_and(data, envp);
		// else if (ft_strcmp("&&", data->args->cmd_args[i]) == 0)
		// 	dobble_and(data, envp);

void	check_redirect(t_data *data)
{
	int		i;

	i = data->args_start;
	while (i <= data->args_end[0])
	{
		if (ft_strcmp("<", data->args->cmd_args[i]) == 0)
			redirect_simple_left(data, i);
		else if (ft_strcmp("<<", data->args->cmd_args[i]) == 0)
			redirect_dobble_left(data, i);
		else if (ft_strcmp(">>", data->args->cmd_args[i]) == 0)
			redirect_dobble_right(data, i);
		else if (ft_strcmp(">", data->args->cmd_args[i]) == 0)
			redirect_simple_right(data, i);
		i++;
	}
}
