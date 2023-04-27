/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:17:19 by kaly              #+#    #+#             */
/*   Updated: 2023/04/04 15:35:41 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/minitalk.h"

void	sig_user(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = -1;

	(void)context;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("\033[91mError: cant send sig to pid : %d\n\033[0m", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0 && !c)
		ft_printf("\033[94m\nClient say : \033[0m");
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(c) - 1;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else if (sig == SIGUSR2)
		c &= ~(1 << bit);
	if (!bit && c)
		ft_putchar_fd(c, 1);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}
int     main(int argc, char **argv)
{
        int     pid;

        (void)argv;
        pid = getpid();
        if (argc != 1)
        {
                ft_printf("\033[91mError: wrong format.\033[0m\n");
                ft_printf("\033[33mtry : ./server\033[0m\n");
                return (0);
        }       
	init_sig(SIGUSR1, &sig_user);
	init_sig(SIGUSR2, &sig_user);
        ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
        ft_printf("\033[90mWaiting for a message...\033[0m\n");
	while (1)
		sleep(1);
        return (0);
}
