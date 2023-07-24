/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:56:53 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/03 11:30:01 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_echo(t_msh *msh)
{
	int	i;

	i = 1;
	while (msh->cmd[i] && !ft_strncmp(msh->cmd[i], "-n", 2))
		i++;
	if (msh->cmd[i])
		ft_printf(msh->cmd[i++]);
	while (msh->cmd[i])
	{
		ft_printf(" %s", msh->cmd[i]);
		i++;
	}
	if (!msh->cmd[1] || ft_strncmp(msh->cmd[1], "-n", 2))
		write(1, "\n", 1);
	msh->status = 0;
}
