/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:42:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/29 04:31:56 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_close(t_data *params)
{
	int	i;

	i = -1;
	while (++i < params->nb_philo)
		pthread_join(params->philo[i].thread, NULL);
	i = -1;
	while (++i < params->nb_philo)
		pthread_mutex_destroy(&(params->fork[i]));
	pthread_mutex_destroy(&(params->mut_is_dead));
	pthread_mutex_destroy(&(params->print_mutex));
	free(params);
	exit(EXIT_SUCCESS);
}

int	ft_check_death(t_philo *philo)
{
	if (((get_time() - philo->life_time) * 1000)
		>= (philo->params->time_to_die + 2000))
	{
		pthread_mutex_lock(&philo->params->mut_is_dead);
		if (philo->params->is_dead == 0)
		{
			pthread_mutex_lock(&philo->params->print_mutex);
			printf("%s%lld ms : Philosophe %d is dead\n",
				R, refresh_time(philo->params), philo->philo_nb);
			pthread_mutex_unlock(&philo->params->print_mutex);
			philo->params->is_dead = 1;
		}
		pthread_mutex_unlock(&philo->params->mut_is_dead);
		return (1);
	}
	return (0);
}

int	ft_is_dead(t_data *params)
{
	pthread_mutex_lock(&params->mut_is_dead);
	if (params->is_dead == 1)
	{
		pthread_mutex_unlock(&params->mut_is_dead);
		return (1);
	}
	pthread_mutex_unlock(&params->mut_is_dead);
	return (0);
}
