/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:36 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/26 15:38:17 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_exec_path(t_msh *msh)
{
	if (!access(msh->cmd[0], X_OK))
		return (ft_strdup(msh->cmd[0]));
	else
		return (ft_strdup("No path"));
}

char	*find_path_2(t_msh *msh, char **path)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		res = ft_strjoin(tmp, msh->cmd[0]);
		free(tmp);
		if (!access(res, X_OK))
		{
			free_double_char(path);
			return (res);
		}
		free(res);
		i++;
	}
	res = ft_strdup(msh->cmd[0]);
	free_double_char(path);
	return (res);
}

char	*find_path(t_msh *msh)
{
	char	**path;
	int		i;

	if (!is_str_in_tab("PATH=", msh->c_env))
		return (ft_strdup("No path"));
	i = 0;
	path = 0;
	while (msh->c_env[i])
	{
		if (!strncmp(msh->c_env[i], "PATH=", 5))
			path = ft_split(ft_strchr(msh->c_env[i], '=') + 1, ':');
		i++;
	}
	if (!path)
		return (ft_strdup("No path"));
	return (find_path_2(msh, path));
}
