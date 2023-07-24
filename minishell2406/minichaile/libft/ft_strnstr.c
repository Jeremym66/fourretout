/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:11:05 by aperrein          #+#    #+#             */
/*   Updated: 2023/02/14 11:33:23 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (!big && !len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		temp = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			temp = (char *)big + i;
			if (little[j + 1] == '\0')
				return (temp);
			j++;
		}
		i++;
	}
	return (NULL);
}
