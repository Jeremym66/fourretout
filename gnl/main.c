/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:26:00 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/03 04:18:39 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>  // lib for printf
#include <fcntl.h>  // lib for open
#include <sys/types.h>
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	argc = argv;
	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s, line");
		free(line);
	}
	return (0);
}
