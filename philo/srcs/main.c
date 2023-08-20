/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:52:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/12 14:52:41 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    print_config_philo(t_data *params, int argc)
{
    printf("%snb_philo : %d\n%s", Y, params->nb_philo, NC);
    printf("%stime_to_die : %d ms\n%s", R, params->time_to_die / 1000, NC);
    printf("%stime_to_eat : %d ms\n%s", B, params->time_to_eat / 1000, NC);
    printf("%stime_to_sleep : %d ms\n%s", G, params->time_to_sleep / 1000, NC);
    if (argc > 5)
        printf("%snumber_of_time_each_philosopher_must_eat : %d\n%s", V, params->number_of_time_each_philosopher_must_eat, NC);
    else
        printf("%snumber_of_time_each_philosopher_must_eat : undefined\n%s", V, NC);
}

int    init_params(t_data *params, char **argv, int argc)
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

int    init_philos(t_data *params)
{
    int i;

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

void    ft_close(t_data *params)
{
    // Attente de la fin des threads
    int i;

    i = -1;
    while (++i < params->nb_philo)
        pthread_join(params->philo[i].thread, NULL);

    // Destruction des mutex
    i = -1;
    while (++i < params->nb_philo)
        pthread_mutex_destroy(&(params->fork[i]));
    pthread_mutex_destroy(&(params->mut_is_dead));
    pthread_mutex_destroy(&(params->print_mutex));
    free(params);
    exit(EXIT_SUCCESS);
}

int ft_check_death(t_philo *philo)
{
    if (((get_time() - philo->life_time) * 1000) >= (philo->params->time_to_die + 5000)) //marge 2ms
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

int    ft_usleep(t_philo *philo, int time)
{
    long long   start;

    start = 0;
    if (((philo->params->nb_philo % 2 == 0) && (philo->params->time_to_die < philo->params->time_to_eat * 2)) 
        || ((philo->params->nb_philo % 2 != 0) && (philo->params->time_to_die < (philo->params->time_to_eat * 2) + philo->params->time_to_sleep)))
        while(start < time)
        {
            if (ft_check_death(philo) == 1)
                return (1);
            start += 5000;
            usleep(5000);
        }
    else
        usleep(time);
    return (0);
}

int    ft_is_dead(t_data *params)
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

int    init_routine(t_philo *philo)
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
            usleep(philo->params->time_to_eat + philo->params->time_to_sleep / 2);
    return(0);
}

void	*thread_routine(void *data)
{   
    int i;
    t_philo *philo;

    philo = (t_philo*)data;
    i = -1;
    if (init_routine(philo) == 1)
        return (NULL);
    // pthread_mutex_lock(&philo->params->print_mutex);
    // philo->params->start_time = get_time();
    // pthread_mutex_unlock(&philo->params->print_mutex);
    while (++i < philo->params->number_of_time_each_philosopher_must_eat && ft_is_dead(philo->params) != 1)   // Chaque philosophe mange 3 fois 
    {   
        if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
            return (NULL); 
        pthread_mutex_lock(&philo->params->fork[philo->left_fork]);
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", G, refresh_time(philo->params));
        printf("Philosophe %d has taken the left fork nb : %d  🍴\n", philo->philo_nb, philo->left_fork);
        pthread_mutex_unlock(&philo->params->print_mutex);
        pthread_mutex_lock(&philo->params->fork[philo->right_fork]);
        if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
        {
            pthread_mutex_unlock(&philo->params->fork[philo->right_fork]);
            pthread_mutex_unlock(&philo->params->fork[philo->left_fork]);
            return (NULL);
        }
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", G, refresh_time(philo->params));
        printf("Philosophe %d has taken the fork nb : %d  🍴\n", philo->philo_nb, philo->right_fork);
        
        printf("%s%lld ms : ", B, refresh_time(philo->params));
        printf("Philosophe %d is eating...\n", philo->philo_nb);
        pthread_mutex_unlock(&philo->params->print_mutex);
        
        philo->life_time = get_time();
        
        usleep(philo->params->time_to_eat);

        pthread_mutex_unlock(&philo->params->fork[philo->right_fork]);
        pthread_mutex_unlock(&philo->params->fork[philo->left_fork]);
        
        if (ft_is_dead(philo->params) != 1)
        {
            pthread_mutex_lock(&philo->params->print_mutex);
            printf("%s%lld ms : ", Y, refresh_time(philo->params));
            printf("Philosophe %d is sleeping...\n", philo->philo_nb);
            pthread_mutex_unlock(&philo->params->print_mutex);
        }
        if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
            return (NULL);
        if (ft_usleep(philo, philo->params->time_to_sleep) == 1)
            return (NULL);
        if (ft_check_death(philo) == 1 || ft_is_dead(philo->params) == 1)
            return (NULL);
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", V, refresh_time(philo->params));
        printf("Philosophe %d is thinking...\n", philo->philo_nb);
        pthread_mutex_unlock(&philo->params->print_mutex);
        if (philo->params->time_to_sleep <= philo->params->time_to_eat)
            if (ft_usleep(philo, philo->params->time_to_eat - philo->params->time_to_sleep + 2000) == 1)
                return (NULL);
        // if (philo->params->nb_philo % 2 != 0)
        // {
        //     if ((philo->philo_nb % 3 == 1) && (i == 0))
        //     {
        //         if (ft_usleep(philo, philo->params->time_to_eat * 2) == 1)
        //             return (NULL);
        //     }
        //     else
        //         if (ft_usleep(philo, philo->params->time_to_eat) == 1)
        //             return (NULL);
        // }
        
    }
    return NULL;
}

int		main(int argc, char **argv)
{
    t_data      *params;
    int         i;

    i = -1;
    params = malloc(sizeof(t_data));
    if (init_params(params, argv, argc) == 0)
        return (EXIT_FAILURE);
    print_config_philo(params, argc);
    if (init_philos(params) == 0)
        return (EXIT_FAILURE);
    // Initialisation des mutex pour les fourchettes
    while (++i < params->nb_philo)
        pthread_mutex_init(&(params->fork[i]), NULL);
    // Création des threads
    i = -1;
    while (++i < params->nb_philo)
        pthread_create(&(params->philo[i].thread), NULL, thread_routine, &(params->philo[i]));
    ft_close(params);
    return (0);
}