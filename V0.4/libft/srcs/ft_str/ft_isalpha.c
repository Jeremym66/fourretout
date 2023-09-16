/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:38:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:03:58 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** These functions check whether c, which must have the value of an unsigned
** char or EOF, falls into a certain character class according to the current
** locale. isalpha() checks for an alphabetic character; in the standard "C"
** locale, it is equivalent to (isupper(c) || islower(c)). In some locales,
** there may be additional characters for which isalpha() is true-letters which
** are neither upper case nor lower case.
**
*/

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
