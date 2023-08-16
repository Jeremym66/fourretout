/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:05:18 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/14 11:00:37 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	create_process(t_phil **philos, t_params *params)
{
	int	cur;

	params->start_time = get_timestamp();
	cur = 0;
	while (cur < params->num)
	{
		(*philos)[cur].pid = fork();
		if ((*philos)[cur].pid == 0)
			return (philo_life(&((*philos)[cur])));
		cur++;
	}
	if (pthread_create(&(params->death_thread), NULL,
			wait_death, philos))
		return (0);
	return (1);
}

int	wait_process(t_phil **philos, t_params *params)
{
	int	cur;
	int	return_code;

	cur = 0;
	return_code = 1;
	while (cur < params->num)
	{
		if (waitpid((*philos)[cur].pid, NULL, 0) == -1)
			return_code = 0;
		cur++;
	}
	return (return_code);
}

int	philo_life(t_phil *phil)
{
	pthread_t	death_thread;

	pthread_create(&death_thread, NULL, check_death, phil);
	if (phil->pos % 2 != 0)
		ft_usleep(phil->params->time_to_eat);
	while (1)
	{
		if (phil->meal_count >= phil->params->meal_max
			&& phil->params->meal_max > 0)
			break ;
		take_fork(phil);
		take_fork(phil);
		write_state("is eating", phil);
		ft_usleep(phil->params->time_to_eat);
		phil->meal_count++;
		sem_wait(phil->sem_last_meal);
		phil->last_meal = get_timestamp() - phil->params->start_time;
		sem_post(phil->sem_last_meal);
		release_forks_and_sleep(phil);
		ft_usleep((phil->params->time_to_die - phil->params->time_to_eat
				- phil->params->time_to_sleep) / 2);
	}
	sem_post(phil->params->finished);
	return (1);
}
