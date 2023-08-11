/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:39:58 by kaly              #+#    #+#             */
/*   Updated: 2023/08/07 11:47:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_envp(t_data *data)
{
	t_envp	*temp;

	temp = data->envp;
	while (data->envp != NULL)
	{
		temp = data->envp;
		data->envp = data->envp->next;
		free(temp->str);
		free(temp);
	}
}
