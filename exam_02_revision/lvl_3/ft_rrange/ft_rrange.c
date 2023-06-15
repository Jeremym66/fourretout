/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:10:40 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/15 11:32:29 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*res;
	int	len;
	int	i;
	
	if (start <= end)
		len = end - start + 1;
	if (len < 0)
		len = -len;
	res = malloc(sizeof(int) * len);
	i = 0;
	if (end > start)
	{
		while (i != len)
		{
			res[i] = end;
			i++;
			end--;
		}
	}
	else
	{
		while (i != len)
		{
			res[i] = end;
			i++;
			end++;
		}
	}
	return (res);
}
