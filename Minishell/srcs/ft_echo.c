/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:29:56 by nours42           #+#    #+#             */
/*   Updated: 2023/08/10 14:49:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	n_time(t_data *d)
{
	int	i;

	i = 2;
	if (ft_strncmp("-n", d->args->cmd_args[d->args_start + 1], 2) == 0)
	{
		while (d->args->cmd_args[d->args_start + 1][i] == 'n')
			i++;
		if (d->args->cmd_args[d->args_start + 1][i] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

void	ft_echo(t_data *d)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (d->args->cmd_args[d->args_start + 1] != NULL
		&& ft_strcmp("<", d->args->cmd_args[d->args_start + 1]) != 0)
	{
		if (n_time(d) && d->args->cmd_args[d->args_start + 2] != NULL)
		{
			i++;
			n++;
		}
		else if (n_time(d) && (d->args->cmd_args[d->args_start + 2] == NULL))
			return ;
		ft_echo2(d, i, n);
		if (n_time(d) == 0)
			ft_printf("\n");
	}
	else
		ft_printf("\n");
	i = -1;
	exit(EXIT_SUCCESS);
}

void	ft_echo2(t_data *d, int i, int n)
{
	while ((d->args_start + i <= d->args_end[0]) && d->args->cmd_args[i]
		&& d->next_part > i)
	{
		i++;
		if ((n == 0 && i == 1) || (n == 1 && i == 2))
			ft_printf("%s", d->args->cmd_args[d->args_start + i]);
		else if (((n == 0 && i > 1) || (n == 1 && i > 2))
			&& d->args_start + i <= d->args_end[0])
			ft_printf(" %s", d->args->cmd_args[d->args_start + i]);
	}
}
