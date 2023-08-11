/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:50:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/10 16:45:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ptd is for parse token and dollar

#include "../includes/minishell.h"

int	find_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			if (s[i + 1] != '$' || s[i + 1] != 63)
				return (i);
		i++;
	}
	return (-1);
}

void	check_in_envp(t_data *d, int i, int j, int index_of_dollar)
{
	t_envp		*copy;

	copy = d->envp;
	while (copy)
	{
		if ((ft_strncmp(d->fr[2], copy->str, j) == 0) && (copy->str[j] == '='))
		{
			free(d->fr[2]);
			d->fr[2] = ft_strndup(copy->str, j + 1);
			free(d->args->cmd_args[i]);
			if (index_of_dollar != 0)
			{
				if (d->fr[2] && d->fr[1])
				{
					d->args->cmd_args[i] = ft_strjoin(d->fr[1], d->fr[2]);
					free(d->fr[2]);
					d->fr[2] = ft_strdup(d->args->cmd_args[i]);
					free(d->args->cmd_args[i]);
				}
			}
			d->args->cmd_args[i] = ft_strjoin(d->fr[2], d->fr[3]);
			break ;
		}
		copy = copy->next;
	}
}

void	ft_init_fr(t_data *data, int i, int j, int index_of_dollar)
{
	data->fr = (char **)malloc(sizeof(char *) * 4);
	data->fr[0] = ft_strdup(data->args->cmd_args[i]);
	data->fr[1] = (char *)malloc(sizeof(char) * index_of_dollar + 2);
	while (++j < index_of_dollar)
		data->fr[1][j] = data->args->cmd_args[i][j];
	if (data->args->cmd_args[i][j + 1] == 32)
	{
		data->fr[1][j] = '$';
		j++;
	}
	data->fr[1][j] = '\0';
	if (data->args->cmd_args[i][index_of_dollar + 1] == 32)
		data->fr[2] = ft_strndup(data->args->cmd_args[i], index_of_dollar);
	else
		data->fr[2] = ft_strndup(data->args->cmd_args[i], index_of_dollar + 1);
	j = ft_find_char(data->fr[2], 0, 32);
	if (j == 0)
		data->fr[3] = NULL;
	else
	{
		data->fr[3] = ft_strndup(data->fr[2], j);
		data->fr[2][j] = '\0';
	}
}

void	find_and_replace(t_data *data, int i, int index_of_dollar)
{
	int			j;

	j = -1;
	ft_init_fr(data, i, j, index_of_dollar);
	j = ft_strlen(data->fr[2]);
	check_in_envp(data, i, j, index_of_dollar);
	if (ft_strncmp(data->args->cmd_args[i], data->fr[0],
			ft_strlen(data->fr[0]) - 1) == 0)
	{
		free(data->args->cmd_args[i]);
		data->args->cmd_args[i] = ft_strjoin(data->fr[1], data->fr[3]);
	}
	free(data->fr[0]);
	free(data->fr[2]);
	free(data->fr[1]);
	if (data->fr[3] != NULL)
		free(data->fr[3]);
	free(data->fr);
}

// void	find_and_replace(t_data *data, int i, int index_of_dollar)
// {
// 	char		**temp;
// 	t_envp		*copy;
// 	int			j;

// 	j = -1;
// 	temp = (char **)malloc(sizeof(char *) * 4);
// 	temp[0] = ft_strdup(data->args->cmd_args[i]);
// 	temp[1] = (char *)malloc(sizeof(char) * index_of_dollar + 2);
// 	while (++j < index_of_dollar)
// 		temp[1][j] = data->args->cmd_args[i][j];
// 	if (data->args->cmd_args[i][j + 1] == 32)
// 	{
// 		temp[1][j] = '$';
// 		j++;
// 	}
// 	temp[1][j] = '\0';
// 	if (data->args->cmd_args[i][index_of_dollar + 1] == 32)
// 		temp[2] = ft_strndup(data->args->cmd_args[i], index_of_dollar);
// 	else
// 		temp[2] = ft_strndup(data->args->cmd_args[i], index_of_dollar + 1);
// 	j = ft_find_char(temp[2], 0, 32);
// 	if (j == 0)
// 		temp[3] = NULL;
// 	else
// 	{
// 		temp[3] = ft_strndup(temp[2], j);
// 		temp[2][j] = '\0';
// 	}
// 	copy = data->envp;
// 	j = ft_strlen(temp[2]);
// 	while (copy)
// 	{
// 		if ((ft_strncmp(temp[2], copy->str, j) == 0) && (copy->str[j] == '='))
// 		{
// 			free(temp[2]);
// 			temp[2] = ft_strndup(copy->str, j + 1);
// 			free(data->args->cmd_args[i]);
// 			if (index_of_dollar != 0)
// 			{
// 				if (temp[2] && temp[1])
// 				{
// 					data->args->cmd_args[i] = ft_strjoin(temp[1], temp[2]);
// 					free(temp[2]);
// 					temp[2] = ft_strdup(data->args->cmd_args[i]);
// 					free(data->args->cmd_args[i]);
// 				}
// 			}
// 			data->args->cmd_args[i] = ft_strjoin(temp[2], temp[3]);
// 			break ;
// 		}
// 		copy = copy->next;
// 	}
// 	if (ft_strncmp(data->args->cmd_args[i], temp[0],
// 			ft_strlen(temp[0]) - 1) == 0)
// 	{
// 		free(data->args->cmd_args[i]);
// 		data->args->cmd_args[i] = ft_strjoin(temp[1], temp[3]);
// 	}
// 	free(temp[0]);
// 	free(temp[2]);
// 	free(temp[1]);
// 	if (temp[3] != NULL)
// 		free(temp[3]);
// 	free(temp);
// }

void	give_me_the_money(t_data *data)
{
	int	i;
	int	index_of_dollar;

	i = data->args_start;
	while (i <= data->args_end[0])
	{
		index_of_dollar = find_dollar(data->args->cmd_args[i]);
		if (index_of_dollar >= 0)
			if (ft_strcmp("$?", data->args->cmd_args[i]) != 0)
				find_and_replace(data, i, index_of_dollar);
		index_of_dollar = 0;
		i++;
	}
}
