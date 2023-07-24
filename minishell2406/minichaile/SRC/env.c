/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:12:57 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/03 10:43:33 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_env(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->cmd[i])
		i++;
	if (i != 1)
		return (ft_putstr_fd("bash: env: too many arguments\n", 2));
	i = 0;
	while (msh->c_env[i])
	{
		if (ft_is_in(msh->c_env[i], '='))
			ft_printf("%s\n", msh->c_env[i]);
		i++;
	}
	msh->status = 0;
}

int	al_before_egal(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '=')
		return (0);
	while (s[i] && pos_egal(s) != i)
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	export_error(t_msh *msh, int j, int *r)
{
	if (!al_before_egal(msh->cmd[j]))
	{
		ft_putstr_fd("bash: export: '", 2);
		ft_putstr_fd(msh->cmd[j], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		msh->status = 2;
		*r = *r + 1;
	}
}
