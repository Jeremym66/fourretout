/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:07:13 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/01 15:23:49 by sdestann         ###   ########.fr       */
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

	if (nmemb == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
