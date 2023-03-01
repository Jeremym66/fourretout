/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavaness <bavaness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:46:26 by bavaness          #+#    #+#             */
/*   Updated: 2023/02/28 20:23:58 by bavaness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_join(char *str, char *str2)
{
	char	*tmp;

	if (str)
	{
		tmp = ft_strjoin(str, str2);
		free(str);
	}
	else
		tmp = ft_strdup(str2);
	return (tmp);
}

char	*gnl_read(int fd, char *str)
{
	char	*buff;
	ssize_t	max;

	max = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
	while (max > 0 && !gnl_have_nl(str))
	{
		max = read(fd, buff, BUFFER_SIZE);
		if (max < 0)
		{
			free(buff);
			return (NULL);
		}
		if (max == 0)
			break ;
		str = clean_join(str, buff);
		ft_bzero(buff, BUFFER_SIZE);
	}
	free(buff);
	return (str);
}

char	*gnl_output(char *str)
{
	size_t	i;
	char	*output;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	output = (char *)malloc((i + 2) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		output[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		output[i++] = '\n';
	output[i] = '\0';
	return (output);
}

char	*gnl_rm_output(char *str)
{
	size_t	i;
	size_t	i2;
	char	*tmp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n' && str[i + 1])
	{
		tmp = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
		ft_bzero(tmp, ft_strlen(str) - i + 1);
		if (!tmp)
			return (NULL);
		i2 = 0;
		while (str[++i])
			tmp[i2++] = str[i];
		free(str);
		return (tmp);
	}
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = gnl_read(fd, str);
	if (!str)
		return (NULL);
	tmp = gnl_output(str);
	str = gnl_rm_output(str);
	return (tmp);
}
