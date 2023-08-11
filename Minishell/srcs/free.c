/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:00:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 13:56:40 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_original_prompt(int i, t_data *data)
{
	if (i == 0)
		return ;
	if (i == 1 && data->original_prompt != NULL)
		free(data->original_prompt);
	else if (i == 2 && data->cmd_prompt != NULL)
		free(data->cmd_prompt);
	else if (i == 3)
	{
		if (data->original_prompt != NULL)
			free(data->original_prompt);
		if (data->cmd_prompt != NULL)
			free(data->cmd_prompt);
	}
}

void	ft_free_all(int i, t_data *data)
{
	ft_free_original_prompt(i, data);
	ft_free_envp(data);
	free_and_clear_args(data);
	free_and_clear_var(data);
	close(data->pipe->infile);
	free(data->pipe);
	free(data);
}
