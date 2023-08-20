/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:36:33 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/08 09:16:10 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_dead(t_phil *phil)
{
	int	alive;

	pthread_mutex_lock(&(phil->params->m_is_dead));
	alive = phil->params->is_dead;
	pthread_mutex_unlock(&(phil->params->m_is_dead));
	return (alive);
}

int	stop_threads(t_phil *phil)
{
	pthread_mutex_lock(&(phil->params->m_is_dead));
	phil->params->is_dead = 1;
	pthread_mutex_unlock(&(phil->params->m_is_dead));
	return (EXIT_FAILURE);
}

int	check_philo_death(t_phil *phil, long cur_time)
{
	int	dead;
	int	last_meal;

	dead = 0;
	pthread_mutex_lock(&(phil->m_last_meal));
	last_meal = cur_time - phil->last_meal;
	pthread_mutex_unlock(&(phil->m_last_meal));
	if (last_meal > phil->params->time_to_die)
	{
		pthread_mutex_lock(&(phil->params->console_mutex));
		pthread_mutex_lock(&(phil->params->m_is_dead));
		phil->params->is_dead = 1;
		pthread_mutex_unlock(&(phil->params->m_is_dead));
		printf("%09ld %d died\n", cur_time, phil->pos);
		pthread_mutex_unlock(&(phil->params->console_mutex));
		dead = 1;
	}
	return (dead);
}

void	*check_philos_death(void *arg)
{
	t_params	*params;
	t_phil		**philos;
	long		cur_time;
	int			cur;

	philos = (t_phil **)arg;
	params = philos[0]->params;
	while (1)
	{
		cur = 0;
		cur_time = get_timestamp() - params->start_time;
		while (cur < params->num)
		{
			if (check_philo_death(&(*philos)[cur], cur_time))
				return (NULL);
			cur++;
		}
		ft_usleep(1);
	}
	return (NULL);
}
