/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:12:44 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:38:46 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_b;
	size_t	i_l;

	i_b = 0;
	i_l = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i_b] && i_b < len)
	{
		i_l = 0;
		while (little[i_l] && i_b + i_l < len)
		{
			if (big[i_b + i_l] != little[i_l])
				break ;
			i_l++;
		}
		if (!little[i_l])
			return ((char *)big + i_b);
		i_b++;
	}
	return (0);
}
