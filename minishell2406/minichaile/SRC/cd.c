/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:36:58 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/20 10:41:11 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_oldpwd(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->c_env[i])
	{
		if (!ft_strncmp(msh->c_env[i], "PWD", 3))
		{
			return (ft_strjoin("OLDPWD=", ft_strchr(msh->c_env[i], '=')));
		}
		i++;
	}
	return (strdup("OLDPWD"));
}

void	update_oldpwd(t_msh *msh, int a)
{
	char	*oldpwd;
	int		i;

	if (a)
		oldpwd = get_oldpwd(msh);
	else
		oldpwd = strdup("OLDPWD");
	i = 0;
	while (msh->c_env[i])
	{
		if (!ft_strncmp(msh->c_env[i], "OLDPWD", 6))
		{
			free(msh->c_env[i]);
			msh->c_env[i] = oldpwd;
		}
		i++;
	}
}

void	update_pwd(t_msh *msh)
{
	int		i;
	char	*pwd;

	i = 0;
	if (!is_str_in_tab("PWD", msh->c_env))
		return ;
	while (msh->c_env[i])
	{
		if (!ft_strncmp(msh->c_env[i], "PWD", 3))
		{
			free(msh->c_env[i]);
			pwd = getcwd(NULL, 0);
			msh->c_env[i] = ft_strjoin("PWD=", pwd);
			free(pwd);
		}
		i++;
	}
	msh->status = 0;
}

void	cmd_cd(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->cmd[i])
		i++;
	if (i < 2)
		return (ft_putstr_fd("bash: cd: one argument needed\n", 2));
	else if (i > 2)
		return (ft_putstr_fd("bash: cd: too many arguments\n", 2));
	if (chdir(msh->cmd[1]) == -1)
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(msh->cmd[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		return (ft_putstr_fd("\n", 2));
	}
	if (is_str_in_tab("OLDPWD", msh->c_env))
	{
		if (is_str_in_tab("PWD", msh->c_env))
			update_oldpwd(msh, 1);
		else
			update_oldpwd(msh, 0);
	}
	update_pwd(msh);
}
