/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:52:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/28 19:12:09 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_eat(t_philo *philo)
{
	if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
		return (1);
	pthread_mutex_lock(&philo->params->fork[philo->left_fork]);
	pthread_mutex_lock(&philo->params->print_mutex);
	printf("%s%lld ms : ", G, refresh_time(philo->params));
	printf("Philosophe %d has taken the left fork nb : %d  🍴\n",
		philo->philo_nb, philo->left_fork);
	pthread_mutex_unlock(&philo->params->print_mutex);
	pthread_mutex_lock(&philo->params->fork[philo->right_fork]);
	if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
	{
		pthread_mutex_unlock(&philo->params->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->params->fork[philo->left_fork]);
		return (1);
	}
	pthread_mutex_lock(&philo->params->print_mutex);
	printf("%s%lld ms : ", G, refresh_time(philo->params));
	printf("Philosophe %d has taken the fork nb : %d  🍴\n",
		philo->philo_nb, philo->right_fork);
	printf("%s%lld ms : ", B, refresh_time(philo->params));
	printf("Philosophe %d is eating...\n", philo->philo_nb);
	pthread_mutex_unlock(&philo->params->print_mutex);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_is_dead(philo->params) != 1)
	{
		pthread_mutex_lock(&philo->params->print_mutex);
		printf("%s%lld ms : ", Y, refresh_time(philo->params));
		printf("Philosophe %d is sleeping...\n", philo->philo_nb);
		pthread_mutex_unlock(&philo->params->print_mutex);
	}
	if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
		return (1);
	if (ft_usleep(philo, philo->params->time_to_sleep) == 1)
		return (1);
	if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
		return (1);
	pthread_mutex_lock(&philo->params->print_mutex);
	printf("%s%lld ms : ", V, refresh_time(philo->params));
	printf("Philosophe %d is thinking...\n", philo->philo_nb);
	pthread_mutex_unlock(&philo->params->print_mutex);
	if (philo->params->time_to_sleep <= philo->params->time_to_eat)
		if (ft_usleep(philo, philo->params->time_to_eat
				- philo->params->time_to_sleep + 2000) == 1)
			return (1);
	return (0);
}

void	*thread_routine(void *data)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)data;
	i = -1;
	if (init_routine(philo) == 1)
		return (NULL);
	while (++i < philo->params->number_of_time_each_philosopher_must_eat
		&& ft_is_dead(philo->params) != 1) 
	{
		if (ft_eat(philo) == 1)
			return (NULL);
		philo->life_time = get_time();
		usleep(philo->params->time_to_eat);
		pthread_mutex_unlock(&philo->params->fork[philo->right_fork]);
		pthread_mutex_unlock(&philo->params->fork[philo->left_fork]);
		if (ft_sleep(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*params;
	int		i;

	i = -1;
	params = malloc(sizeof(t_data));
	if (init_params(params, argv, argc) == 0)
		return (EXIT_FAILURE);
	print_config_philo(params, argc);
	if (init_philos(params) == 0)
		return (EXIT_FAILURE);
	while (++i < params->nb_philo)
		pthread_mutex_init(&(params->fork[i]), NULL);
	i = -1;
	while (++i < params->nb_philo)
		pthread_create(&(params->philo[i].thread), NULL, thread_routine,
			&(params->philo[i]));
	ft_close(params);
	return (0);
}
