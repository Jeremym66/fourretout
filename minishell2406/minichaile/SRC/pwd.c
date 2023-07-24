/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:10:37 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/20 10:42:10 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	l_egal(char *s)
{
	if (pos_egal(s) >= 0)
		return (pos_egal(s));
	else
		return (ft_strlen(s));
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	cmd_pwd(t_msh *msh)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_printf("%s\n", pwd);
	free(pwd);
	msh->status = 0;
}
