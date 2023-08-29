/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:52:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/28 19:33:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define NC "\e[0m"
# define Y  "\e[1;33m"
# define R  "\e[1;31m"
# define G  "\e[1;32m"
# define B  "\e[1;34m"
# define V  "\e[1;35m"

typedef struct s_philo
{
	struct s_data	*params;
	long long		life_time;
	pthread_t		thread;
	int				pos;
	int				philo_nb;
	int				left_fork;
	int				right_fork;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	mut_is_dead;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	print_mutex;
	long long		start_time;
	t_philo			philo[250];
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_each_philosopher_must_eat;
	int				is_dead;
}	t_data;

//  main.c  //

int			ft_eat(t_philo *philo);
int			ft_sleep(t_philo *philo);
void		*thread_routine(void *data);
int			main(int argc, char **argv);

//  dead.c  //

void		ft_close(t_data *params);
int			ft_check_death(t_philo *philo);
int			ft_is_dead(t_data *params);

//  init.c  //

void		print_config_philo(t_data *params, int argc);
int			init_params(t_data *params, char **argv, int argc);
int			init_philos(t_data *params);
int			init_routine(t_philo *philo);

//  utils.c //

int			ft_atoi(const char *str);
long long	refresh_time(t_data *data);
long long	get_time(void);
void		ft_swap(int *a, int *b);
int			ft_usleep(t_philo *philo, int time);

#endif
