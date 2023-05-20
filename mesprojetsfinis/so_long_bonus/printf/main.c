/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:33:46 by jmetezea          #+#    #+#             */
/*   Updated: 2023/05/19 20:06:30 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char	*coucou;

	coucou = NULL;
	ft_printf("%p // %p // %p // %p\n\n", (void *) - 1, 15, ULONG_MAX, LONG_MIN);
	printf("%p // %p // %p // %p\n\n", (void *) - 1, (void *)15,
		(void *)ULONG_MAX, (void *)LONG_MIN);
	ft_printf("%%, %c, %s, %d, %i, %u, %X, %x, %p, %p \n", 'c', "coucou",
		42, -42, -2147483646, -1658, -1203658, &coucou, coucou);
	printf("%%, %c, %s, %d, %i, %u, %X, %x, %p, %p \n", 'c', "coucou",
		42, -42, -2147483646, -1658, -1203658, &coucou, coucou);
	return (0);
}
