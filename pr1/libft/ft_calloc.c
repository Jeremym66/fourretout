/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:57 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:43:04 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tmp;
	void	*ret;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	tmp = size * nmemb;
	if (tmp / size != nmemb)
		return (NULL);
	ret = malloc(size * nmemb);
	if (ret == NULL)
		return (malloc(0));
	ft_bzero(ret, tmp);
	return (ret);
}
