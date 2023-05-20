/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:41:54 by kaly              #+#    #+#             */
/*   Updated: 2023/05/20 17:50:35 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	ft_check(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_map(int fd)
{
	char	buffer;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
		line = NULL;
	line = malloc(1);
	line[0] = '\0';
	while (!ft_check(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &buffer, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = ft_join(line, buffer);
	}
	return (line);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	i = -1;
	while (data->p[++i])
		free(data->p[i]);
	free(data->p);
	ft_printf("Error!\nThe map haven't a good format.\n");
	free(data);
}

void	ft_check_map(char **argv, t_data *data)
{
	char	*buffer;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	buffer = ft_get_map(fd);
	if (buffer == NULL || fd == -1)
	{
		free(data);
		ft_printf("Error!\nThe map could not be read.\n");
		exit (EXIT_FAILURE);
	}	
	data->map = ft_split(buffer, '\n');
	data->p = ft_split(buffer, '\n');
	free(buffer);
	init_player(data);
	if (ft_check_limits(data) == 1)
	{
		ft_free_map(data);
		exit (EXIT_FAILURE);
	}
	else
		ft_printf("Nice!\nThe map is good.\n");
}
