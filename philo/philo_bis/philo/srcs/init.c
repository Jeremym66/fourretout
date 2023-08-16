/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:38:23 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/08 09:16:19 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_philo(t_phil *phil, t_fork **forks, t_params *params, int cur)
{
	phil->params = params;
	phil->pos = cur;
	phil->last_meal = 0;
	phil->meal_count = 0;
	phil->r_fork = &((*forks)[cur]);
	phil->r_taken = 0;
	phil->l_taken = 0;
	if (cur == params->num - 1)
		phil->l_fork = &((*forks)[0]);
	else
		phil->l_fork = &((*forks)[cur + 1]);
	phil->l_fork->used = 0;
	pthread_mutex_init(&(phil->m_last_meal), NULL);
	pthread_mutex_init(&(phil->l_fork->lock), NULL);
}

int	create_philos(t_phil **philos, t_fork **forks, t_params	*params)
{
	int	cur;

	*philos = malloc(sizeof(t_phil) * params->num);
	if (!(*philos))
		return (0);
	*forks = malloc(sizeof(t_fork) * params->num);
	if (!(*forks))
	{
		free(*philos);
		return (0);
	}
	cur = 0;
	while (cur < params->num)
	{
		init_philo(&(*philos)[cur], forks, params, cur);
		cur++;
	}
	return (1);
}

int	init_params(t_params *params, int argc, char **argv)
{
	if (argc < 5)
	{
		ft_printf("Usage : ./philo number_philos time_die ");
		ft_printf("time_eat time_sleep [number_eat]\n");
		return (0);
	}
	params->num = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->meal_max = -1;
	if (argc > 5)
	{
		params->meal_max = ft_atoi(argv[5]);
		if (ft_atoi(argv[5]) < 0)
			return (0);
	}
	params->is_dead = 0;
	if (params->num <= 0 || params->time_to_die < 0 || params->time_to_eat < 0
		|| params->time_to_sleep < 0)
		return (0);
	pthread_mutex_init(&(params->console_mutex), NULL);
	pthread_mutex_init(&(params->m_is_dead), NULL);
	return (1);
}
