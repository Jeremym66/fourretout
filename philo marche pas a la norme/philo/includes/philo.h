/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:52:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/12 14:52:41 by jmetezea         ###   ########.fr       */
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
	pthread_t   thread;
	int         pos;
	int			philo_nb;
    int			left_fork;
	int			right_fork;
	long long   life_time;
	struct s_data     *params;
}   t_philo;

typedef struct s_data
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_time_each_philosopher_must_eat;
    long long        start_time;
	int					is_dead;
	pthread_mutex_t		fork[250];
	pthread_mutex_t		print_mutex;
	t_philo     philo[250];
}				t_data;

//  main.c  //

void    print_config_philo(t_data *params);
int     init_params(t_data *params, char **argv, int argc);
int		init_philos(t_data *params);
int		main(int argc, char **argv);

//  utils.c //

int			ft_atoi(const char *str);
long long	refresh_time(t_data *data);
long long	get_time(void);
void	ft_swap(int *a, int *b);

#endif