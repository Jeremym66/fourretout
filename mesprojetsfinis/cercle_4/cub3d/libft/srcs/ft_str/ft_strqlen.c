/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strqlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:47:29 by sebastien         #+#    #+#             */
/*   Updated: 2023/05/11 11:31:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** The strqlen() function calculates the length of a quote in the string pointed
** by s, strating at the n index.
**
*/

size_t	ft_strqlen(const char *str, int n, char c)
{
	size_t	len;

	len = 0;
	while (str[n] != c)
	{
		if (str[n] == '\0')
		{
			len = 0;
			break ;
		}
		else
		{
			len++;
			n++;
		}
	}
	return (len);
}

/*int	main(void)
{
	int test;

	test = ft_strqlen("test avec 'quote dans une quote'", 11, 39);
	test = ft_strqlen("test avec quote dans une quote", 6, 113);
	(void)test;
	return (0);
}*/
