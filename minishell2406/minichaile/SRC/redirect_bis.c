/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:26:55 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/28 13:36:34 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_cmd(t_msh *msh, int f, int i)
{
	int		j;
	char	**new;

	j = 0;
	if (f)
	{
		while (msh->cmd[j])
			j++;
		new = malloc(sizeof(char *) * (j - f +1));
		new[j - f] = 0;
		j = 0;
		while (j < i && msh->cmd[j][0] != '<' && msh->cmd[j][0] != '>')
		{
			new[j] = ft_strdup(msh->cmd[j]);
			j++;
		}
		while (msh->cmd[j + f])
		{
			new[j] = ft_strdup(msh->cmd[j + f]);
			j++;
		}
		free_double_char(msh->cmd);
		msh->cmd = new;
	}
}

int	syntax_error(int i)
{
	(void)i;
	ft_putstr_fd("bash: syntax error near redirection token \n", 2);
	return (1);
}

int	check_redirect(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->cmd[i +1])
	{
		if (msh->cmd[i][0] == '>' && msh->cmd[i +1][0] == '<')
			return (syntax_error(0));
		else if (msh->cmd[i][0] == '<' && msh->cmd[i +1][0] == '>')
			return (syntax_error(0));
		else if ((msh->cmd[i][0] == '>' && msh->cmd[i +1][0] == '>') \
			|| (msh->cmd[i][0] == '<' && msh->cmd[i +1][0] == '<'))
		{
			if (!msh->cmd[i +2])
				return (syntax_error(0));
			else if ((msh->cmd[i +2][0] == '<' || msh->cmd[i +2][0] == '>' \
				|| msh->cmd[i +2][0] == '|' || msh->cmd[i +2][0] == '&'))
				return (syntax_error(i++));
		}
		i++;
	}
	if (msh->cmd[i][0] == '>' || msh->cmd[i][0] == '<')
		return (syntax_error(0));
	return (0);
}
