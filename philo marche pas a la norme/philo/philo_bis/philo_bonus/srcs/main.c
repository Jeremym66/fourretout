/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:24:42 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/14 11:10:15 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	free_all(t_phil *philos, t_params *params, int exit_code)
{
	free(philos);
	sem_close(params->sem_forks);
	sem_close(params->sem_console);
	sem_close(params->finished);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_phil		*philos;
	int			return_code;

	return_code = EXIT_SUCCESS;
	if (!init_params(&params, argc, argv))
		return (EXIT_FAILURE);
	if (!create_philos(&philos, &params))
		return (EXIT_FAILURE);
	if (!create_process(&philos, &params))
		return_code = stop_process(&philos, &params);
	if (!wait_process(&philos, &params))
		return (free_all(philos, &params, EXIT_FAILURE));
	return (free_all(philos, &params, return_code));
}
