/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:24:34 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/08 09:11:22 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"

typedef struct s_params
{
	pthread_t	death_thread;
	int			num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meal_max;
	long		start_time;
	sem_t		*sem_console;
	sem_t		*sem_forks;
	sem_t		*finished;
}	t_params;

typedef struct s_phil
{
	pid_t		pid;
	int			pos;
	long		last_meal;
	sem_t		*sem_last_meal;
	int			meal_count;
	t_params	*params;
}	t_phil;

// death.c
void	*check_death(void *arg);
void	*wait_death(void *arg);
int		stop_process(t_phil **philos, t_params *params);
// forks.c
void	take_fork(t_phil *phil);
void	release_forks_and_sleep(t_phil *phil);
// init.c
int		create_philos(t_phil **philos, t_params	*params);
int		init_params(t_params *params, int argc, char **argv);
// main.c
int		philo_life(t_phil *phil);
// process.c
int		create_process(t_phil **philos, t_params *params);
int		wait_process(t_phil **philos, t_params *params);
// utils.c
void	ft_usleep(long int time_in_ms);
void	write_state(char *str, t_phil *phil);
long	get_timestamp(void);
#endif
