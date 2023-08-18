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

void    print_config_philo(t_data *params)
{
    printf("%snumber_of_philosophers : %d\n%s", Y, params->number_of_philosophers, NC);
    printf("%stime_to_die : %d ms\n%s", R, params->time_to_die / 1000, NC);
    printf("%stime_to_eat : %d ms\n%s", B, params->time_to_eat / 1000, NC);
    printf("%stime_to_sleep : %d ms\n%s", G, params->time_to_sleep / 1000, NC);
    printf("%snumber_of_time_each_philosopher_must_eat : %d\n%s", V, params->number_of_time_each_philosopher_must_eat, NC);
}

int    init_params(t_data *params, char **argv, int argc)
{
    if (argc < 5)
    {
        printf("Warning!!\nYou must write ./philo <number_of_philosophers>"); 
        printf(" <time_to_die> <time_to_eat> <time_to_sleep>");
        printf(" <[number_of_times_each_philosopher_must_eat]>\n");
        return (0);
    }
    params->number_of_philosophers = ft_atoi(argv[1]);
    params->time_to_die = ft_atoi(argv[2]) * 1000;
    params->time_to_eat = ft_atoi(argv[3]) * 1000;
    params->time_to_sleep = ft_atoi(argv[4]) * 1000;
    if (argc > 5)
        params->number_of_time_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
         params->number_of_time_each_philosopher_must_eat = __INT_MAX__;
    pthread_mutex_init(&(params->print_mutex), NULL);
    params->is_dead = 0;
    return (1);
}

int    init_philos(t_data *params)
{
    int i;

    i = -1;
    while (++i < params->number_of_philosophers)
    {
        params->philo[i].pos = i;
        params->philo[i].philo_nb = i + 1;
        params->philo[i].left_fork = i;
        params->philo[i].right_fork = (i + 1) % params->number_of_philosophers;
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
    while (++i < params->number_of_philosophers)
        pthread_join(params->philo[i].thread, NULL);

    // Destruction des mutex
    i = -1;
    while (++i < params->number_of_philosophers)
        pthread_mutex_destroy(&(params->fork[i]));
    free(params);
    exit(EXIT_SUCCESS);
}

int ft_check_death(t_philo *philo)
{
    // printf("Philosophe %d\n", philo->philo_nb);
    // printf("get %lld\n", (get_time() - philo->life_time) * 1000);
    // printf("Philosophe %d\n", philo->philo_nb);
    // printf("time to die %d\n", (philo->params->time_to_die + 2000));
    if (((get_time() - philo->life_time) * 1000) >= (philo->params->time_to_die + 2000)) //marge 2ms
    {
        pthread_mutex_lock(&philo->params->print_mutex);
        if (philo->params->is_dead == 0)
        {
            printf("%s%lld ms : ", R, ((philo->life_time + philo->params->time_to_die - philo->params->start_time) / 1000));
            printf("Philosophe %d is dead\n", philo->philo_nb);
            philo->params->is_dead = 1;
        }
        pthread_mutex_unlock(&philo->params->print_mutex);
        return (1);
    }
    return (0);
}

int    ft_usleep(t_philo *philo, int time)
{
    long long   start;

    start = 0;
    printf("time : %d\n", time);
    printf("philo %d life time : %lld\n", philo->philo_nb, philo->life_time);
    while(start < time)
    {
        if (ft_check_death(philo) == 1)
        {
            ft_close(philo->params);
            return (1);
        }
        start += 10000;
        usleep(10000);
    }
    return (0);
}

void	*thread_routine(void *data)
{   
    int i;
    int mut;
    t_philo *philo;
    
    philo = (t_philo*)data;
    i = -1;


    if(philo->philo_nb == philo->params->number_of_philosophers)
            ft_swap(&philo->right_fork, &philo->left_fork);
    pthread_mutex_lock(&philo->params->print_mutex);
    printf("%s%lld ms : ", R, refresh_time(philo->params));
    printf("Philosophe %d entre dans la boucle\n", philo->philo_nb);
    pthread_mutex_unlock(&philo->params->print_mutex); 
    if (philo->pos % 2 != 0)
    {
        usleep(philo->params->time_to_eat);
        if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
        {
            printf("Philosophe %d returning\n", philo->philo_nb);
            return (NULL);
        }
    }
    if (philo->params->number_of_philosophers % 2 != 0)
    {
        if (philo->philo_nb % 3 == 0)
        {
            usleep(philo->params->time_to_eat * 2);
            if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
            {
                printf("Philosophe %d returning\n", philo->philo_nb);
                return (NULL);
            }
        }
    }
    while (++i < philo->params->number_of_time_each_philosopher_must_eat && philo->params->is_dead != 1)   // Chaque philosophe mange 3 fois 
    {   
        while (mut == 1)
        {
            if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
                return (NULL);
            mut = pthread_mutex_lock(&philo->params->fork[philo->left_fork]);
            if (mut == 0)
                pthread_mutex_lock(&philo->params->fork[philo->right_fork]);
            usleep(1000);
            printf("test\n");
        }
        pthread_mutex_lock(&philo->params->print_mutex);
        if (philo->params->is_dead != 1)
        {
            printf("%s%lld ms : ", G, refresh_time(philo->params));
            printf("Philosophe %d take the fork nb : %d  🍴\n", philo->philo_nb, philo->right_fork);
            printf("%s%lld ms : ", G, refresh_time(philo->params));
            printf("Philosophe %d take the fork nb : %d  (left)\n", philo->philo_nb, philo->left_fork);
        }
        pthread_mutex_unlock(&philo->params->print_mutex); 

       // MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANGE //
        
        pthread_mutex_lock(&philo->params->print_mutex);
        if (philo->params->is_dead != 1)
        {
            printf("%s%lld ms : ", B, refresh_time(philo->params));
            printf("Philosophe %d mange...\n", philo->philo_nb);
        }
        pthread_mutex_unlock(&philo->params->print_mutex);
        
        if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
            return (NULL);

        // printf("life time avant : %lld\n", get_time() - philo->life_time);
        philo->life_time = get_time();
        // printf("life time apres : %lld\n", get_time() - philo->life_time);

        
        usleep(philo->params->time_to_eat);
        if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
        {
            printf("Philosophe %d return\n", philo->philo_nb);
            return (NULL);
        }

        pthread_mutex_lock(&philo->params->print_mutex);
        if (philo->params->is_dead != 1)
        {
            printf("%s%lld ms : ", B, refresh_time(philo->params));
            printf("Philosophe %d a fini de manger.\n", philo->philo_nb);
        }
        pthread_mutex_unlock(&philo->params->print_mutex);

        // MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANGE //

        // pthread_mutex_lock(&philo->params->print_mutex);
        // printf("%s%lld ms : ", Y, refresh_time(philo->params));
        // printf("Philosophe %d put down the fork nb : %d  🍴\n", philo->philo_nb, philo->right_fork);
        // pthread_mutex_unlock(&philo->params->print_mutex);

        pthread_mutex_unlock(&philo->params->fork[philo->right_fork]);
        pthread_mutex_unlock(&philo->params->fork[philo->left_fork]);
       
        // pthread_mutex_lock(&philo->params->print_mutex);
        // printf("%s%lld ms : ", Y, refresh_time(philo->params));
        // printf("Philosophe %d put down the fork nb : %d  (left)\n", philo->philo_nb, philo->left_fork);
        // pthread_mutex_unlock(&philo->params->print_mutex);


        pthread_mutex_lock(&philo->params->print_mutex);
        if (philo->params->is_dead != 1)
        {
            printf("%s%lld ms : ", V, refresh_time(philo->params));
            printf("Philosophe %d is sleeping...\n", philo->philo_nb);
        }
        pthread_mutex_unlock(&philo->params->print_mutex);



        if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
            return (NULL);
        usleep(philo->params->time_to_sleep);
        if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
            return (NULL);



        // if((ft_usleep(philo, philo->params->time_to_sleep)) == 1)    // Temps pour digérer
        //     exit(EXIT_SUCCESS);
        pthread_mutex_lock(&philo->params->print_mutex);
        if (philo->params->is_dead != 1)
        {
            printf("%s%lld ms : ", V, refresh_time(philo->params));
            printf("Philosophe %d is thinking...\n", philo->philo_nb);
        }
        pthread_mutex_unlock(&philo->params->print_mutex);
        if (ft_check_death(philo) == 1 || philo->params->is_dead == 1)
            return (NULL);
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
    print_config_philo(params);
    if (init_philos(params) == 0)
        return (EXIT_FAILURE);
    // Initialisation des mutex pour les fourchettes
    while (++i < params->number_of_philosophers)
        pthread_mutex_init(&(params->fork[i]), NULL);
    // Création des threads
    i = -1;
    while (++i < params->number_of_philosophers)
        pthread_create(&(params->philo[i].thread), NULL, thread_routine, &(params->philo[i]));
    ft_close(params);
    return (0);
}

// void	*thread_routine(void *data)
// {
//     unsigned int *a;
    
//     a = (unsigned int *)data;
// 		// La fonction pthread_self() renvoie
// 		// l'identifiant propre à ce thread.
// 	//tid = pthread_self();
// 	printf("%sThread [%ls]: Le plus grand ennui c'est d'exister sans vivre.%s\n",
// 		B, a, NC);
// 	return (NULL);	 // Le thread termine ici.
// }

// void    je_philo(t_data *philo)
// {
//     pthread_t	tid1;	// Identifiant du premier thread
// 	pthread_t	tid2;	// Identifiant du second thread
//     int         id1;
//     int         id2;

//     (void)philo;
// 	id1 = 1;
//     id2 = 2;
//     	// Création du premier thread qui va directement aller
// 		// exécuter sa fonction thread_routine.
// 	pthread_create(&tid1, NULL, thread_routine, &id1);
// 	printf("Main: Creation du premier thread [%ld] id : %d\n", tid1 , id1);
// 		// Création du second thread qui va aussi exécuter thread_routine.
// 	pthread_create(&tid2, NULL, thread_routine, &id2);
// 	printf("Main: Creation du second thread [%ld] id : %d\n", tid2, id2);
// 		// Le main thread attend que le nouveau thread
// 		// se termine avec pthread_join.
// 	pthread_join(tid1, NULL);
// 	printf("Main: Union du premier thread [%ld]\n", tid1);
// 	pthread_join(tid2, NULL);
// 	printf("Main: Union du second thread [%ld]\n", tid2);
// }

// int		main(int argc, char **argv)
// {
//     t_data  *philo;


//     if (argc < 5)
//     {
//         printf("Warning!!\nYou must write ./philo <number_of_philosophers>"); 
//         printf(" <time_to_die> <time_to_eat> <time_to_sleep>");
//         printf(" <[number_of_times_each_philosopher_must_eat]>\n");
//         return(EXIT_FAILURE);
//     }
//     philo = (t_data *)malloc(sizeof(t_data));
//     init_philo(philo, argv, argc);
//     print_config_philo(philo);
//     test_time();
//     je_philo(philo);
//     free(philo);
//     return (0);
// }