/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:38:23 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/08 11:00:57 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_philo(t_phil *phil, t_params *params, int cur)
{
	char	*pos_str;
	char	*sem_name;

	phil->params = params;
	phil->pos = cur;
	phil->last_meal = 0;
	phil->meal_count = 0;
	pos_str = ft_itoa(phil->pos);
	sem_name = ft_strjoin("/sem_last_meal", pos_str);
	sem_unlink(sem_name);
	phil->sem_last_meal = sem_open(sem_name, O_CREAT, 0644, 1);
	sem_unlink(sem_name);
	free(pos_str);
	free(sem_name);
}

int	create_philos(t_phil **philos, t_params	*params)
{
	int	cur;

	*philos = malloc(sizeof(t_phil) * params->num);
	if (!(*philos))
		return (0);
	cur = 0;
	while (cur < params->num)
	{
		init_philo(&(*philos)[cur], params, cur);
		cur++;
	}
	return (1);
}

void	init_sem(t_params *params)
{
	sem_unlink("/sem_forks");
	sem_unlink("/sem_console");
	sem_unlink("/finished");
	params->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, params->num);
	params->sem_console = sem_open("/sem_console", O_CREAT, 0644, 1);
	params->finished = sem_open("/finished", O_CREAT, 0644, 1);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_console");
	sem_unlink("/finished");
	sem_wait(params->finished);
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
	if (params->num <= 0 || params->time_to_die < 0 || params->time_to_eat < 0
		|| params->time_to_sleep < 0)
		return (0);
	init_sem(params);
	return (1);
}
