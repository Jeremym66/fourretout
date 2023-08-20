/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:58:26 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/12 14:00:06 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"

// thread_routine est la fonction que le thread invoque directement
// après sa création. Le thread se termine à la fin de cette fonction.

void	*thread_routine(void *data)
{
	pthread_t tid;

		// La fonction pthread_self() renvoie
		// l'identifiant propre à ce thread.
	tid = pthread_self();
	printf("%sThread [%ld]: Le plus grand ennui c'est d'exister sans vivre.%s\n",
		YELLOW, tid, NC);
	return (NULL);	 // Le thread termine ici.
}

int	main(void)
{
	pthread_t	tid1;	// Identifiant du premier thread
	pthread_t	tid2;	// Identifiant du second thread

		// Création du premier thread qui va directement aller
		// exécuter sa fonction thread_routine.
	pthread_create(&tid1, NULL, thread_routine, NULL);
	printf("Main: Creation du premier thread [%ld]\n", tid1);
		// Création du second thread qui va aussi exécuter thread_routine.
	pthread_create(&tid2, NULL, thread_routine, NULL);
	printf("Main: Creation du second thread [%ld]\n", tid2);
		// Le main thread attend que le nouveau thread
		// se termine avec pthread_join.
	pthread_join(tid1, NULL);
	printf("Main: Union du premier thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Union du second thread [%ld]\n", tid2);
	return (0);
}
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t forks[5];  // Un mutex pour chaque fourchette
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;  // Mutex pour l'affichage
int next_philosopher = 0;  // Indice du prochain philosophe à manger

void	*thread_routine(void *data)
{
    unsigned int *a = (unsigned int *)data;
    
    int id = *a;
    int left_fork = id;
    int right_fork = (id + 1) % 5;
    
    for (int i = 0; i < 3; i++) {  // Chaque philosophe mange 3 fois
        usleep(1000);  // Temps pour penser
        
        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);
        
        pthread_mutex_lock(&print_mutex);
        printf("Philosophe %d mange...\n", id);
        pthread_mutex_unlock(&print_mutex);
        
        usleep(2000);  // Temps pour manger
        
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
        
        pthread_mutex_lock(&print_mutex);
        printf("Philosophe %d a fini de manger.\n", id);
        pthread_mutex_unlock(&print_mutex);
        
        usleep(1000);  // Temps pour digérer
    }
    
    return NULL;
}

int main()
{
    pthread_t philosophers[5];
    unsigned int ids[5] = {0, 1, 2, 3, 4};

    // Initialisation des mutex pour les fourchettes
    for (int i = 0; i < 5; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Création des threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&philosophers[i], NULL, thread_routine, &ids[i]);
    }

    // Attente de la fin des threads
    for (int i = 0; i < 5; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destruction des mutex
    for (int i = 0; i < 5; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
