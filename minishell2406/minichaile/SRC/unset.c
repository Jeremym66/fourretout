/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:22:27 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/20 10:39:46 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	not_doublon(char **s, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (!ft_strncmp(s[i], s[j], ft_strlen(s[j])))
			return (0);
		i++;
	}
	return (1);
}

int	count_unset(t_msh *msh)
{
	int	r;
	int	i;
	int	j;

	j = 1;
	r = 0;
	while (msh->cmd[j])
	{
		i = 0;
		while (msh->c_env[i])
		{
			if (!(ft_strncmp(msh->cmd[j], msh->c_env[i], \
				max(ft_strlen(msh->cmd[j]), l_egal(msh->c_env[i]))))
				&& not_doublon(msh->cmd, j))
				r++;
			i++;
		}
		j++;
	}
	return (r);
}

int	check_unset(t_msh *msh, char *s)
{
	int	i;
	int	m;

	i = 1;
	while (msh->cmd[i])
	{
		m = max(ft_strlen(msh->cmd[i]), ft_strlen(s));
		if (!ft_strncmp(msh->cmd[i], s, m))
			return (1);
		i++;
	}
	return (0);
}

void	cmd_unset(t_msh *msh)
{
	char	**res;
	int		i;
	int		j;

	if (!msh->cmd[1])
	{
		ft_printf("unset: not enough arguments\n");
		return ;
	}
	i = 0;
	while (msh->c_env[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1 - count_unset(msh)));
	i = 0;
	j = 0;
	while (msh->c_env[i])
	{	
		if (!is_str_in_tab(msh->c_env[i], msh->cmd))
			res[j++] = ft_strdup(msh->c_env[i]);
		free(msh->c_env[i++]);
	}
	res[j] = 0;
	free(msh->c_env);
	msh->c_env = res;
	msh->status = 0;
}
