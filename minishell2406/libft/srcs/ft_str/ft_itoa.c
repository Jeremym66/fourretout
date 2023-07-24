/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:57:22 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/12 10:04:14 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* DESCRIPTION :
**
** Allocates (with malloc(3)) and returns a string representing the integer
** received as an argument. Negative numbers must be handled.
**
*/

static int	ft_isnegative(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	ft_intlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n_value;
	int		i;
	int		j;

	n_value = n;
	i = ft_intlen(n);
	j = ft_isnegative(n);
	str = malloc(sizeof(char) * (i + 1));
	n_value *= j;
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n_value == 0)
		str[i] = '0';
	while (n_value > 0)
	{
		str[i--] = n_value % 10 + '0';
		n_value /= 10;
	}
	if (j == -1)
		str[i] = '-';
	return (str);
}
