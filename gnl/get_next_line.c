/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:12:04 by jmetezea          #+#    #+#             */
/*   Updated: 2023/03/01 01:41:41 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_and_stash(int fd, static char *stash)
{
	ssize_t		ret_read;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))
	if (!buf)
		return (NULL);
	ret_read = read(fd, buf, BUFFER_SIZE);

}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 1, 0) < 0)
		return (NULL);
	line = NULL;
	//  lire fd pour le mettre dans stash
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	//  extraire stash dans line
	//  clear le stash
	return (line);
}



/* il me faut 	un buffer (buf) pour stocker la lecture grace a read
		un static char* (stash) pour stocker le buffer au fur et a mesure des lectures
 		dans lequel on checkera a chaque implémentation du buf s'il y a un /n ou /0 
 		lorsque ce sera le cas on deplacera jusqu'au /n inclus dans un char* (line) 
