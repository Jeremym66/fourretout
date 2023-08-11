/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:19:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/10 16:12:45 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_args(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_args[++i])
		ft_printf("d->args->cmd_args[%d] : |%s| \n", i, data->args->cmd_args[i]);
}

void	ft_print_args_with_start_and_end(t_data *data)
{
	int	i;

	i = data->args_start;
	ft_printf("data->args_start : %d\n", data->args_start);
	ft_printf("data->args_end[0] : %d\n", data->args_end[0]);
	while (data->args_end[i])
	{
		ft_printf("d->args->cmd_args[%d] : |%s| \n", i, data->args->cmd_args[i]);
		i++;
	}
}

void	msg_error(char *err)
{
	perror(err);
	exit(1);
}

void	print_var(t_data *data)
{
	int	i;

	i = -1;
	ft_printf("data->var (t_var)\n");
	ft_printf("quote_type : %d\n", data->var->quote_type);
	ft_printf("str = %s\n", data->var->str);
	ft_printf("word = %s\n", data->var->word);
	while (data->var->commands[++i])
		ft_printf("commands[%d] : %s\n", i, data->var->commands[i]);
	ft_printf("num_words : %d\n", (int)data->var->num_words);
	ft_printf("i : %d\n", (int)data->var->i);
	if (data->args->cmd_args)
	{
		ft_printf("data->var->cmd_args (t_args)\n");
		ft_print_args(data);
	}
}

// void	print_all(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	if (data->var)
// 		print_var(data);
// 	if (data->pipe)
// 	{
// 		ft_printf("data->pipe (t_pipe)\n");
// 		ft_print_args_with_start_and_end(data);
// 	}
// 	if (data)
// 	{
// 		ft_printf("data (t_data)\n");
// 		ft_printf("original_prompt = %s\n", data->original_prompt);
// 		ft_printf("cmd_prompt = %s\n", data->cmd_prompt);
// 		ft_printf("redirected : %d\n", data->redirected);
// 		ft_printf("fd_redirect_in : %d\n", data->fd_redirect_in);
// 		ft_printf("fd_redirect_out : %d\n", data->fd_redirect_out);
// 		ft_printf("next_part : %d\n", data->next_part);
// 		ft_printf("args_start : %d\n", data->args_start);
// 		while (data->args_end[++i])
// 			ft_printf("*args_end : %d\n", data->args_end[i]);
// 		ft_printf("args_max : %d\n", data->args_max);
// 		ft_printf("end : %d\n", data->end);
// 		ft_printf("boucle : %d\n", data->boucle);
// 	}
// }
