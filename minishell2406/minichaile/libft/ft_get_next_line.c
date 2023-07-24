/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:30:41 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/24 14:20:06 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*delete_line(char *save, int i)
{
	char	*new;

	new = NULL;
	if (!save[i])
	{
		free(save);
		return (new);
	}
	if (save[i])
		new = strdup_line(save, i);
	free(save);
	return (new);
}

char	*check_line(char *save)
{
	char	*line;
	int		i;
	int		len;

	if (!save || !save[0])
		return (NULL);
	i = 0;
	len = 0;
	while (save[len] && save[len] != '\n')
		len++;
	if (save[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		b;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	b = 1;
	while (b != 0 && !strchr_line(str, '\n'))
	{
		b = read(fd, buffer, BUFFER_SIZE);
		buffer[b] = '\0';
		if (buffer)
			str = strjoin_line(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*save[1000];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save[fd] = read_line(fd, save[fd]);
	res = check_line(save[fd]);
	if (save[fd])
		save[fd] = delete_line(save[fd], strlen_line(res));
	return (res);
}
