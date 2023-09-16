/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strqnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:47:29 by sebastien         #+#    #+#             */
/*   Updated: 2023/06/19 09:53:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** The strqnlen() function calculates the length of a quote in the string pointed
** by s, strating at the n index.
** a quote, here, is a part of the string who start at first char c and stop at
** the second. the char c is out of the count.
**
*/

size_t	ft_strqnlen(const char *str, int n, char c)
{
	size_t			len;
	static int		i = 0;

	len = 0;
	while (str[n] != c && str[n])
		n++;
	if (str[n] == '\0')
		return (0);
	else
	{
		i = 1;
		n++;
	}
	while (str[n] != c && str[n])
	{
		n++;
		len++;
	}
	if (str[n] == c)
		i = 2;
	if (i == 2)
		return (len);
	else
		return (0);
	return (0);
}

/*int	main(void)
{
	int	test;

	test = ft_strqnlen("test avec 'quote' dans 'une quote", 0, '\'');
	printf("%d\n", test);
	test = ft_strqnlen("test avec uoteq dans une quote", 0, 'z');
	printf("%d\n", test);
	(void)test;
	return (0);
}*/
