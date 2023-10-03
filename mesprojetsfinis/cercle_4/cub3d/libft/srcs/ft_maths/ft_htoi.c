/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:57:22 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/26 10:15:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** The  htoi function converts the initial portion of the string pointed (*str)
** in to an hexadecimal.
** i = 0, n = 0 et c = s[i]
*/

int	ft_htoi(char *s, int i, int n, int c)
{
	while (c != '\0')
	{
		c = s[i];
		n *= 16;
		if (i == 0 && c == '0')
		{
			c = s[++i];
			if (c != 'x' && c != 'X')
				--i;
			else
				c = s[++i];
		}
		else if (c >= '0' && c <= '9')
			n += c - '0';
		else if (c >= 'a' && c <= 'f')
			n += 10 + (c - 'a');
		else if (c >= 'A' && c <= 'F')
			n += 10 + (c - 'A');
		else
			return (n);
		i++;
	}
	return (n);
}
