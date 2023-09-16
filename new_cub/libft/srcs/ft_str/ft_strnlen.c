/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:47:29 by sebastien         #+#    #+#             */
/*   Updated: 2023/07/04 14:08:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** la fonction strnlen renvoie la longueur d'une string comme un strlen mais
** elle commence a compter a l'index i.
**
*/

size_t	ft_strnlen(const char *str, size_t i)
{
	size_t	len;

	len = i;
	if (i <= ft_strlen(str))
	{
		while (str[len])
			len++;
	}
	else
		len = 0;
	return (len);
}
