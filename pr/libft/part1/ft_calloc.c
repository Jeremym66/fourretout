/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:47 by maserrie          #+#    #+#             */
/*   Updated: 2023/02/07 23:32:42 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*mem;
	size_t	temp;

	temp = (size_t)(len * size);
	if (len == 0 || size == 0)
		return (malloc(0));
	if (temp / len != size || temp / size != len)
		return (NULL);
	mem = malloc(temp);
	if (mem)
		ft_bzero(mem, temp);
	return (mem);
}
