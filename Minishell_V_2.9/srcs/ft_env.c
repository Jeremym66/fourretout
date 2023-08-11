/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:30:25 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 11:04:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_envp(t_data *data)
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
	free(show_envp);
	exit(EXIT_SUCCESS);
}
