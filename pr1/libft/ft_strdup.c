/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:10:43 by aramon            #+#    #+#             */
/*   Updated: 2023/02/18 18:37:06 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*d;
	int		s_len;

	s_len = (int)ft_strlen(s);
	d = (char *)malloc(sizeof(char) * (s_len + 1));
	if (d == NULL)
		return (0);
	i = -1;
	while (s[++i])
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}
