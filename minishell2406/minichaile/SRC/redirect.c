/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:37:13 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/04 10:10:16 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	delimeter(t_msh *msh, int i)
{
	int		fd;
	char	*tmp;

	fd = open("make.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	tmp = get_next_line(0);
	if (!tmp)
		return (-1);
	while (strncmp(msh->cmd[i + 1], tmp, ft_strlen(msh->cmd[i + 1]))
		|| (ft_strlen(tmp) -1) > ft_strlen(msh->cmd[i + 1]))
	{
		ft_putstr_fd(tmp, fd);
		free(tmp);
		tmp = get_next_line(0);
	}
	free(tmp);
	close(fd);
	fd = open("make.tmp", O_RDONLY);
	dup2(fd, 0);
	close(fd);
	msh->redirected_in = 1;
	return (3);
}

int	simple_in(t_msh *msh, int i)
{
	int	fd;

	fd = open(msh->cmd[i + 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(msh->cmd[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	dup2(fd, 0);
	close(fd);
	msh->redirected_in = 1;
	return (2);
}

int	append_end(t_msh *msh, int i)
{
	int	fd;

	fd = open(msh->cmd[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, 1);
	close(fd);
	msh->redirected_out = 1;
	return (3);
}

int	simple_end(t_msh *msh, int i)
{
	int	fd;

	fd = open(msh->cmd[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, 1);
	close(fd);
	msh->redirected_out = 1;
	return (2);
}

int	redirect_sort(t_msh *msh)
{
	int	i;
	int	f;

	i = 0;
	msh->status = 2;
	if (check_redirect(msh))
		return (1);
	while (msh->cmd[i])
	{
		f = 0;
		if (msh->cmd[i][0] == '>' && msh->cmd[i +1][0] != '>')
			f = simple_end(msh, i);
		else if (msh->cmd[i][0] == '>' && msh->cmd[i +1][0] == '>')
			f = append_end(msh, i +1);
		else if (msh->cmd[i][0] == '<' && msh->cmd[i +1][0] != '<')
			f = simple_in(msh, i);
		else if (msh->cmd[i][0] == '<' && msh->cmd[i +1][0] == '<')
			f = delimeter(msh, i +1);
		if (f == -1)
			return (1);
		new_cmd(msh, f, i);
		if (!f)
			i++;
	}
	return (0);
}
