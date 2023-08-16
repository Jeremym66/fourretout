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
    printf("%stime_to_die : %d\n%s", R, params->time_to_die, NC);
    printf("%stime_to_eat : %d\n%s", B, params->time_to_eat, NC);
    printf("%stime_to_sleep : %d\n%s", G, params->time_to_sleep, NC);
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
         params->number_of_time_each_philosopher_must_eat = 0;
    pthread_mutex_init(&(params->print_mutex), NULL);
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

void	*thread_routine(void *data)
{   
    int i;
    t_philo *philo;
    
    philo = (t_philo*)data;
    i = -1;
    if(philo->philo_nb == philo->params->number_of_philosophers)
            ft_swap(&philo->right_fork, &philo->left_fork);
    pthread_mutex_lock(&philo->params->print_mutex);
    printf("%s%lld ms : ", R, refresh_time(philo->params));
    printf("Philosophe %d entre dans la boucle\n", philo->philo_nb);
    pthread_mutex_unlock(&philo->params->print_mutex); 
    while (++i < philo->params->number_of_time_each_philosopher_must_eat)   // Chaque philosophe mange 3 fois 
    {
        

        pthread_mutex_lock(&philo->params->fork[philo->left_fork]);
        pthread_mutex_lock(&philo->params->fork[philo->right_fork]);
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", G, refresh_time(philo->params));
        printf("Philosophe %d take the fork nb : %d  🍴\n", philo->philo_nb, philo->right_fork);
        pthread_mutex_unlock(&philo->params->print_mutex); 
        
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", G, refresh_time(philo->params));
        printf("Philosophe %d take the fork nb : %d  (left)\n", philo->philo_nb, philo->left_fork);
        pthread_mutex_unlock(&philo->params->print_mutex);
       
       // MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANGE //

        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", B, refresh_time(philo->params));
        printf("Philosophe %d mange...\n", philo->philo_nb);
        pthread_mutex_unlock(&philo->params->print_mutex);

        usleep(philo->params->time_to_eat);  // Temps pour manger
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", B, refresh_time(philo->params));
        printf("Philosophe %d a fini de manger.\n", philo->philo_nb);
        pthread_mutex_unlock(&philo->params->print_mutex);

        // MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAANGE //

        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", Y, refresh_time(philo->params));
        printf("Philosophe %d put down the fork nb : %d  🍴\n", philo->philo_nb, philo->right_fork);
        pthread_mutex_unlock(&philo->params->print_mutex);

        pthread_mutex_unlock(&philo->params->fork[philo->right_fork]);
        pthread_mutex_unlock(&philo->params->fork[philo->left_fork]);
       
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", Y, refresh_time(philo->params));
        printf("Philosophe %d put down the fork nb : %d  (left)\n", philo->philo_nb, philo->left_fork);
        pthread_mutex_unlock(&philo->params->print_mutex);

        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", V, refresh_time(philo->params));
        printf("Philosophe %d dort...\n", philo->philo_nb);
        pthread_mutex_unlock(&philo->params->print_mutex);
        usleep(philo->params->time_to_sleep);  // Temps pour digérer
        pthread_mutex_lock(&philo->params->print_mutex);
        printf("%s%lld ms : ", V, refresh_time(philo->params));
        printf("Philosophe %d fini de dormir...\n", philo->philo_nb);
        pthread_mutex_unlock(&philo->params->print_mutex);

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
    {
        pthread_mutex_init(&(params->fork[i]), NULL);
    }

    // Création des threads
    i = -1;
    while (++i < params->number_of_philosophers)
        pthread_create(&(params->philo[i].thread), NULL, thread_routine, &(params->philo[i]));

    // Attente de la fin des threads
    i = -1;
    while (++i < params->number_of_philosophers)
        pthread_join(params->philo[i].thread, NULL);

    // Destruction des mutex
    i = -1;
    while (++i < params->number_of_philosophers)
        pthread_mutex_destroy(&(params->fork[i]));
    free(params);
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