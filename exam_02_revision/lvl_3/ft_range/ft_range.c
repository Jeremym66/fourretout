/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:35:38 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/31 17:13:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	i;
	int	*array;

	if (start < end)
		len = end - start + 1;
	if (start > end)
		len = start - end + 1;
	if (start == end)
		len = 1;
	array = malloc(sizeof(int) * len);
	i = -1;
	if (start < end)
	{
		while(i++ < len)
			array[i] = start++;
	}
	else if (start > end)
	{
		while(i++ < len)
			array[i] = start--;
	}
	else
		array[0] = start;
	return (array);
}
