#include <stdio.h>
#include <pthread.h>

// Chaque thread comptera TIMES_TO_COUNT fois
#define TIMES_TO_COUNT 21000

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

void	*thread_routine(void *data)
{
	// Chaque thread commence ici
	pthread_t	tid;
	unsigned int	*count; // pointeur vers la variable dans le main
	unsigned int	i;

	tid = pthread_self();
	count = (unsigned int *)data;
	// On imprime le compte avant que ce thread commence
	// a itérer
	printf("%sThread [%ld]: compte au depart = %u.%s\n",
		YELLOW, tid, *count, NC);
	i = 0;
	while (i < TIMES_TO_COUNT)
	{
		// On itere TIMES_TO_COUNT fois
		// On incremente le compte a chaque iteration
		(*count)++;
		i++;
	}
	// On imprime le compte final au moment ou ce thread
	// a termine son propre compte
	printf("%sThread [%ld]: Compte final = %u.%s\n",
		BYELLOW, tid, *count, NC);
	return (NULL); // Thread termine ici.
}

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;
	// Variable pour contenir le compte des deux threads :
	unsigned int	count;

	count = 0;
	// Vu que chaque thread va compter TIMES_TO_COUNT fois et qu'on va
	// avoir 2 threads, on s'attend a ce que le compte final soit
	// 2 * TIMES_TO_COUNT :
	printf("Main: Le compte attendu est de %s%u%s\n", GREEN, 
					2 * TIMES_TO_COUNT, NC);
	// Creation des threads :
	pthread_create(&tid1, NULL, thread_routine, &count);
	printf("Main: Creation du premier thread [%ld]\n", tid1);
	pthread_create(&tid2, NULL, thread_routine, &count);
	printf("Main: Creation du second thread [%ld]\n", tid2);
	// Recuperation des threads :
	pthread_join(tid1, NULL);
	printf("Main: Union du premier thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Union du second thread [%ld]\n", tid2);
	// Evaluation du compte final :
	if (count != (2 * TIMES_TO_COUNT))
		printf("%sMain: ERREUR ! Le compte est de %u%s\n", RED, count, NC);
	else
		printf("%sMain: OK. Le compte est de %u%s\n", GREEN, count, NC);
	return (0);
}
