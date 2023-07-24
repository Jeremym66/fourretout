/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:12:14 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/11 13:41:38 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_oldpwd(t_envp *envp)
{
	t_envp	*copy;

	copy = envp;
	while (copy)
	{
		if (ft_strncmp(copy->str, "PWD", 3) == 0)
		{
			return (ft_strjoin("OLDPWD=", ft_strchr(copy->str, '=')));
		}
		copy = copy->next;
	}
	return (strdup("OLDPWD"));
}

void	update_oldpwd(t_envp *envp, int a)
{
	char	*oldpwd;
	t_envp	*copy;

	copy = envp;
	if (a)
		oldpwd = get_oldpwd(copy);
	else
		oldpwd = strdup("OLDPWD");
	while (copy)
	{
		if (ft_strncmp(copy->str, "OLDPWD", 6) == 0)
		{
			free(copy->str);
			copy->str = oldpwd;
		}
		copy = copy->next;
	}
}

void	update_pwd(t_data *data)
{
	char	*pwd;

	ft_unset(data, "PWD");
	pwd = getcwd(NULL, 0);
	ft_add_new_arg_envp(data, ft_strjoin("PWD=", pwd));
	free(pwd);
}

void	ft_cd(t_data *data)
{
	int		i;
	t_data	*dup;
	char	*pwd;
	char	*oldpwd;

	i = 0;
	dup = data;
	while (dup->args->cmd_args[i])
		i++;
	if (i < 2)
		return (ft_putstr_fd("bash: cd: one argument needed\n", 2));
	else if (i > 2)
		return (ft_putstr_fd("bash: cd: too many arguments\n", 2));
	dup = data;
	oldpwd = getcwd(NULL, 0);
	if (chdir(dup->args->cmd_args[1]) == -1)
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(dup->args->cmd_args[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		return (ft_putstr_fd("\n", 2));
	}
	pwd = getcwd(NULL, 0);
	ft_unset(data, "OLDPWD");
	ft_unset(data, "PWD");
	ft_add_new_arg_envp(data, ft_strjoin("OLDPWD=", oldpwd));
	ft_add_new_arg_envp(data, ft_strjoin("PWD=", pwd));
	free(oldpwd);
	free(pwd);
}
