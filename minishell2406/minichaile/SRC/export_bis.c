/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:47:24 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/27 11:15:24 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pos_egal(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (!s[i])
		return (-1);
	return (i);
}

int	ieme_env(char *s, t_msh *msh)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (msh->c_env[i])
	{
		if (ft_strncmp(s, msh->c_env[i], ft_strlen(s)) > 0)
			r++;
		i++;
	}
	return (r);
}

void	write_ieme(t_msh *msh, int i)
{
	int	j;
	int	k;

	j = 0;
	while (ieme_env(msh->c_env[j], msh) != i)
		j++;
	if (msh->c_env[j][0] != '_')
	{
		k = 0;
		ft_printf("declare -x ");
		while (k < pos_egal(msh->c_env[j]) + 1 || \
			(pos_egal(msh->c_env[j]) < 0 && msh->c_env[j][k]))
			ft_putchar_fd(msh->c_env[j][k++], 1);
		if (k <= (int)ft_strlen(msh->c_env[j]) && pos_egal(msh->c_env[j]) >= 0)
		{
			ft_putstr_fd("\"", 1);
			while (msh->c_env[j][k])
				ft_putchar_fd(msh->c_env[j][k++], 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
	}
}

void	export_noarg(t_msh *msh)
{
	int	e;
	int	i;

	e = 0;
	i = 0;
	while (msh->c_env[e])
		e++;
	while (i < e)
	{
		write_ieme(msh, i);
		i++;
	}
}

void	cmd_export(t_msh *msh)
{
	if (!msh->cmd[1])
		export_noarg(msh);
	else
	{
		export_arg(msh);
		if (is_str_in_tab("PWD", msh->cmd))
			update_pwd(msh);
	}
	if (msh->status == 1)
		msh->status = 0;
	else
		msh->status = 1;
}
