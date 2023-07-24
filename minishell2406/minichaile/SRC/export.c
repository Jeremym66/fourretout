/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:33:23 by aperrein          #+#    #+#             */
/*   Updated: 2023/06/27 13:58:07 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Compte le nombre de doublon 
int	count_same_export(t_msh *msh)
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
				max(l_egal(msh->cmd[j]), l_egal(msh->c_env[i])))))
				r++;
			i++;
		}
		export_error(msh, j, &r);
		j++;
	}
	return (r);
}

//Verifie que la valeur ne sera pas remplace
//dans la suite des arguments de export
int	not_in_export(t_msh *msh, char *s, int a)
{
	int	i;

	i = 1;
	while (msh->cmd[i + a])
	{
		if (!(ft_strncmp(msh->cmd[i + a], s, max(l_egal(s), \
			l_egal(msh->cmd[i + a])))) && pos_egal(msh->cmd[i + a]) >= 0)
			return (0);
		i++;
	}
	return (1);
}

//Verifie si la valeur quon veut rajouter n'y est pas deja
int	not_in_res(char **res, char *s)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (!ft_strncmp(res[i], s, max(l_egal(s), l_egal(res[i]))))
			return (0);
		i++;
	}
	return (1);
}

//Suite de export_arg
//cette partie rajoute les arguments de export a l'environnement
void	export_arg_2(t_msh *msh, int i, char **res)
{
	int	j;

	j = 1;
	while (msh->cmd[j])
	{
		if (not_in_export(msh, msh->cmd[j], j) && not_in_res(res, msh->cmd[j])
			&& al_before_egal(msh->cmd[j]))
		{
			res[i++] = ft_strdup(msh->cmd[j]);
			res[i] = 0;
		}
		j++;
	}
	free(msh->c_env);
	msh->c_env = res;
}

//Mets a jour le nouveau environnement
//cette partie conseve les anciennes valeurs non modifiees
void	export_arg(t_msh *msh)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (msh->c_env[i])
		i++;
	while (msh->cmd[j])
		j++;
	res = malloc(sizeof(char *) * (i + j - count_same_export(msh)));
	i = 0;
	j = 0;
	while (msh->c_env[i])
	{
		if (not_in_export(msh, msh->c_env[i], 0))
			res[j++] = ft_strdup(msh->c_env[i]);
		free(msh->c_env[i++]);
	}
	res[j] = 0;
	export_arg_2(msh, j, res);
}
