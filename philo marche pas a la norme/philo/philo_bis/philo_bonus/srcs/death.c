/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:36:33 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/14 12:33:05 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	stop_process(t_phil **philos, t_params *params)
{
	int	cur;

	cur = 0;
	while (cur < params->num)
		kill((*philos)[cur++].pid, SIGTERM);
	return (EXIT_FAILURE);
}

void	*check_death(void *arg)
{
	t_phil		*phil;
	t_params	*params;
	int			cur_time;

	phil = (t_phil *)arg;
	params = phil->params;
	while (1)
	{
		cur_time = get_timestamp() - params->start_time;
		if (cur_time - phil->last_meal > phil->params->time_to_die)
		{
			sem_wait(phil->params->sem_console);
			ft_printf("%09d %d died\n", cur_time, phil->pos);
			sem_post(phil->params->finished);
		}
		ft_usleep(1);
	}
	return (NULL);
}

void	*wait_death(void *arg)
{
	t_phil		**philos;
	t_params	*params;

	philos = (t_phil **)arg;
	params = philos[0]->params;
	sem_wait(params->finished);
	stop_process(philos, params);
	return (NULL);
}
