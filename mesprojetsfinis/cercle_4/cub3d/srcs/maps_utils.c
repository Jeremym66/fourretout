/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 15:16:49 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	resize_map(t_data *data)
{
	int		i;

	data->size_max = 0;
	i = data->map_first_line - 1;
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) > data->size_max)
			data->size_max = ft_strlen(data->map[i]);
	}
	i = data->map_first_line - 1;
	add_spaces(data);
}

void	add_spaces(t_data *data)
{
	char	*res;
	int		j;
	size_t	len;

	j = data->map_first_line - 1;
	while (data->map[++j])
	{
		len = ft_strlen(data->map[j]);
		if (len < data->size_max && j != data->map_last_line
			&& len != data->size_max - 1)
		{
			res = data->map[j];
			data->map[j] = ft_realloc_space(res, len - 1, data->size_max + 1);
		}
	}
}

void	*ft_realloc_space(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_memblock;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size <= original_size)
		return (ptr);
	new_memblock = malloc(new_size);
	if (ptr)
	{
		if (!new_memblock)
			return (NULL);
		ft_memcpy(new_memblock, ptr, original_size);
		ft_memset2(new_memblock + original_size, ' ', new_size - original_size);
		free(ptr);
	}
	return (new_memblock);
}

void	*ft_memset2(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	len--;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	c = 0;
	*str = (unsigned char)c;
	return (b);
}
