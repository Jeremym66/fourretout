/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:52:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/12 14:52:41 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

// void start_time(void)
// {
//     long    start_time;
//     long    now;
//     long    time;

//     start_time = get_time();
//     time2 = get_time();
//     time3 = time2 - time1;
//     printf("%stime diff : %ld ms\n%s", Y, time3, NC);
// }
long long	refresh_time(t_data *data)
{
	long long	time;

	time = get_time() - data->start_time;
	
	// pthread_mutex_lock(&(data->print_mutex));
	// printf("%stime : %lld ms\n%s", Y, time, NC);
	// pthread_mutex_unlock(&(data->print_mutex));
	return(time);
}

long long   get_time(void)
{
    struct timeval  tv;
    long long     time;

    gettimeofday(&tv, NULL);
    time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    //printf("%stime : %lld\n%s", Y, time, NC);
    return (time);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}