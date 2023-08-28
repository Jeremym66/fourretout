/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:33:40 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/28 18:47:59 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_config_philo(t_data *params, int argc)
{
	printf("%snb_philo : %d\n%s", Y, params->nb_philo, NC);
	printf("%stime_to_die : %d ms\n%s", R, params->time_to_die / 1000, NC);
	printf("%stime_to_eat : %d ms\n%s", B, params->time_to_eat / 1000, NC);
	printf("%stime_to_sleep : %d ms\n%s", G, params->time_to_sleep / 1000, NC);
	if (argc > 5)
		printf("%snumber_of_time_each_philosopher_must_eat : %d\n%s", V,
			params->number_of_time_each_philosopher_must_eat, NC);
	else
	{
		printf("%snumber_of_time_each_philosopher_must_eat", V);
		printf(" : undefined\n");
	}
}

int	init_params(t_data *params, char **argv, int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Warning!!\nYou must write ./philo <nb_philo>");
		printf(" <time_to_die> <time_to_eat> <time_to_sleep>");
		printf(" <[number_of_times_each_philosopher_must_eat]>\n");
		return (0);
	}
	params->nb_philo = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]) * 1000;
	params->time_to_eat = ft_atoi(argv[3]) * 1000;
	params->time_to_sleep = ft_atoi(argv[4]) * 1000;
	params->number_of_time_each_philosopher_must_eat = __INT_MAX__;
	if (argc > 5)
		params->number_of_time_each_philosopher_must_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&(params->print_mutex), NULL);
	if (params->nb_philo <= 0 || params->time_to_die < 0
		|| params->time_to_eat < 0 || params->time_to_sleep < 0
		|| params->number_of_time_each_philosopher_must_eat < 0)
		return (0);
	params->is_dead = 0;
	pthread_mutex_init(&(params->mut_is_dead), NULL);
	return (1);
}

int	init_philos(t_data *params)
{
	int	i;

	i = -1;
	while (++i < params->nb_philo)
	{
		params->philo[i].pos = i;
		params->philo[i].philo_nb = i + 1;
		params->philo[i].left_fork = i;
		params->philo[i].right_fork = (i + 1) % params->nb_philo;
		params->philo[i].life_time = get_time();
		params->philo[i].params = params;
	}
	params->start_time = get_time();
	return (1);
}

int	init_routine(t_philo *philo)
{
	if (philo->params->nb_philo == 1)
	{
		usleep(philo->params->time_to_die);
		pthread_mutex_lock(&philo->params->print_mutex);
		printf("%s%lld ms : Philosophe %d is dead\n",
			R, refresh_time(philo->params), philo->philo_nb);
		pthread_mutex_unlock(&philo->params->print_mutex);
		return (1);
	}
	if (philo->philo_nb == philo->params->nb_philo)
		ft_swap(&philo->right_fork, &philo->left_fork);
	if (philo->pos % 2 != 0)
		usleep(philo->params->time_to_eat);
	if (philo->params->nb_philo % 2 != 0)
		if (philo->philo_nb % 3 == 0)
			usleep(philo->params->time_to_eat
				+ philo->params->time_to_sleep / 2);
	return (0);
}
