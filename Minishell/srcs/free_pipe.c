/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:25:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 13:58:35 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// pour info :

// typedef struct s_pipe
// {
// 	int			infile;
// 	int			outfile;
// 	int			pipe_fd[2];
// 	int			cmd_nbrs;
// 	int			nbr_of_pipe;
// 	int			idx;
// }				t_pipe;

// void	init_pipe(t_data *data)
// {
// 	data->pipe = (t_pipe *)malloc(sizeof(t_pipe));
// 	data->pipe->nbr_of_pipe = 0;
// 	data->pipe->infile = dup(STDIN_FILENO);
// 	data->pipe->outfile = dup(STDOUT_FILENO);
// 	data->pipe->idx = 0;
// 	data->pipe->cmd_nbrs = 0;
// }

void	free_and_clear_pipe(t_data *data)
{
	data->pipe->cmd_nbrs = 0;
	data->pipe->nbr_of_pipe = 0;
	data->pipe->idx = 0;
	close(data->pipe->infile);
	close(data->pipe->outfile);
	free(data->pipe);
}
