/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:13:47 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/09 15:19:39 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	a;

	i = 0;
	a = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			a = i;
		i++;
	}
	if ((char)c == 0)
		return ((char *)(s + i));
	else if (a >= 0)
		return ((char *)(s + a));
	return (NULL);
}	
