/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:42:23 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/07 21:59:13 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	duplicate_env(char **env, t_msh *msh)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	msh->c_env = malloc(sizeof(char *) * (i + 1));
	if (!msh->c_env)
		return ;
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "SHLVL", 5))
		{
			msh->lvl = ft_itoa(ft_atoi(ft_strchr(env[i], '=') + 1) + 1);
			msh->c_env[i] = ft_strjoin("SHLVL=", msh->lvl);
		}
		else
			msh->c_env[i] = ft_strdup(env[i]);
		i++;
	}
	msh->c_env[i] = 0;
}

int	main(int argc, char *argv[], char **env)
{
	t_msh				msh;

	msh.gnl = 0;
	msh.status = 0;
	msh.l = NULL;
	msh.cmd = NULL;
	msh.parsed = NULL;
	msh.std_in = dup(0);
	msh.std_out = dup(1);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "gnl", 3))
			msh.gnl = 1;
	}
	duplicate_env(env, &msh);
	minishell(&msh);
	return (EXIT_SUCCESS);
}
