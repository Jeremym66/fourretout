/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:07:13 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/22 22:06:24 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** La fonction calloc() alloue la mémoire nécessaire pour un tableau de nmemb
** éléments de size octets, et renvoie un pointeur vers la mémoire allouée.
** Cette zone est remplie avec des zéros. Si nmemb ou si size est nulle, calloc
** renvoie soit NULL ou un unique pointeur qui pourra être passé ultérieurement
** à free() avec succès.
**
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
