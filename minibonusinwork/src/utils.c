/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:02:18 by kaly              #+#    #+#             */
/*   Updated: 2023/04/30 15:02:35 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/minitalk.h"

char	*ft_strjoinc(char *s1, char c)
{
	int		i;
	char	*str;

	if (!s1 || !c)
		exit(EXIT_FAILURE);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str)
		exit(EXIT_FAILURE);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	i++;
	str[i] = 0;
	free(s1);
	return (str);
}

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	susr;

	susr.sa_sigaction = handler;
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&susr.sa_mask);
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &susr, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &susr, 0);
}
