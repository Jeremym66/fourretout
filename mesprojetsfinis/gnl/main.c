/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:26:00 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/04 00:45:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 0)
		argv[0] = 0;
	fd = open("coucou", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
