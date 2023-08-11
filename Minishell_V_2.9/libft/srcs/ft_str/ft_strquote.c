/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strquote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:13:01 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/11 12:33:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
	the ft_strquote take a str pointed by s, find the first char c, get to the 
	last, and return the malloced str in the two c.
	exemple : s = "it s an exemple with a 'quote in simple quote'"
	if c == ', return "quote in simple quote"
*/

char	*ft_strquote(char *s, int index, char c)
{
	int		size;
	int		quote_index;
	char	*res;

	size = 0;
	quote_index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			size = ft_strqlen(s, index + 1, c);
			break ;
		}
		index++;
	}
	index++;
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return ("");
	while (size > 0)
	{
		res[quote_index++] = s[index++];
		size--;
	}
	return (res);
}

/*int	main(void)
{
	char *test;

	test = ft_strquote("test avec 'quote dans une quote'", 9, 39);
	free(test);
	test = ft_strquote("", 0, 39);
	free(test);
	test = ft_strquote(" ", 0, 39);
	free(test);
	test = ft_strquote("test avec \"quote dans une quote\"", 9, 39);
	free(test);
	test = ft_strquote("test avec \"quote dans une quote\"", 9, 34);
	free(test);
	test = ft_strquote("test avec quote 'dans une quote", 6, 39);
	free(test);
	test = ft_strquote("test avec quote \"dans une quote", 6, 34);
	free(test);
	(void)test;
	return (0);
}*/
