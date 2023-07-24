/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:29:15 by aperrein          #+#    #+#             */
/*   Updated: 2023/07/04 13:40:16 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal2(int n)
{
	if (n == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (n == SIGQUIT)
		ft_printf("\b\b  \b\b");
}

void	ft_signal(struct sigaction *act, t_msh *msh)
{
	(void)msh;
	act->sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&act->sa_mask);
	act->sa_handler = &ft_signal2;
	sigaction(SIGINT, act, NULL);
	sigaction(SIGQUIT, act, NULL);
}
