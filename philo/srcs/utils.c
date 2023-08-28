/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:52:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/28 19:42:22 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

long long	refresh_time(t_data *data)
{
	long long	time;

	time = get_time() - data->start_time;
	return (time);
}

long long	get_time(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_usleep(t_philo *philo, int time)
{
	long long	start;
	int			i;

	start = 0;
	i = 0;
	if (((philo->params->nb_philo % 2 == 0)
			&& (philo->params->time_to_die < philo->params->time_to_eat * 2))
		|| ((philo->params->nb_philo % 2 != 0) && (philo->params->time_to_die
				< (philo->params->time_to_eat * 2)
				+ philo->params->time_to_sleep)))
	{
		while (start < time)
		{
			i = ft_check_death(philo);
			if (i == 1)
				return (1);
			start += 5000;
			usleep(5000);
		}
	}
	else
		usleep(time);
	return (0);
}
