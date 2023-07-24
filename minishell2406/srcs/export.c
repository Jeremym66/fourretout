/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/07/11 12:40:09 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_add_new_arg_envp(t_data *data, char *args)
{
	t_envp	*copy;
	t_envp	*new;

	new = (t_envp *)malloc(sizeof(t_envp));
	new->str = args;
	new->next = NULL;
	copy = data->envp;
	while (copy->next)
		copy = copy->next;
	copy->next = new;
}

char	*ft_before_and_equal(char *s)
{
	int		index;
	char	*before;

	index = 0;
	before = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (s[index - 1] != '=')
	{
		before[index] = s[index];
		index++;
	}
	before[index] = '\0';
	return (before);
}

void	ft_export(t_data *data, char *args)
{
	char	*before;
	t_envp	*copy;

	copy = data->envp;
	data->str_temp = ft_strchr(args, '=');
	if (data->str_temp != NULL)
	{
		before = ft_before_and_equal(args);
		while (copy)
		{
			if (ft_strcmp(copy->str, before) == 0
				&& ft_isalnum(copy->str[ft_strlen(before) + 1]))
				ft_unset(data, args);
			copy = copy->next;
		}
		ft_add_new_arg_envp(data, args);
	}
	else
	{
		ft_putstr_fd("bash: export: '", 2);
		ft_putstr_fd(args, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
}
