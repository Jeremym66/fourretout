/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:24:42 by ocartier          #+#    #+#             */
/*   Updated: 2022/03/10 18:36:46 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	free_all(t_phil*philos, t_fork *forks, int exit_code)
{
	free(philos);
	free(forks);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_phil		*philos;
	t_fork		*forks;
	int			return_code;

	return_code = EXIT_SUCCESS;
	if (!init_params(&params, argc, argv))
		return (EXIT_FAILURE);
	if (!create_philos(&philos, &forks, &params))
		return (EXIT_FAILURE);
	if (!create_threads(&philos, &params))
		return_code = stop_threads(&philos[0]);
	if (!wait_threads(&philos, &params))
		return (free_all(philos, forks, EXIT_FAILURE));
	return (free_all(philos, forks, return_code));
}
