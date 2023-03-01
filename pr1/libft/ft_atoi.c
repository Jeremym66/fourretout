/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:16:38 by aramon            #+#    #+#             */
/*   Updated: 2023/02/15 23:40:14 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	check_errors(const char *nptr, int *sign, int *i)
{
	int	sign_count;

	sign_count = 0;
	while (ft_isspace(nptr[*i]))
		(*i)++;
	while (nptr[*i] == '-')
	{
		(*sign) *= -1;
		if (nptr[*i + 1] == '-' && nptr[*i + 1] != '\0')
			return (0);
		sign_count++;
		(*i)++;
	}
	if (nptr[*i] == '+' && sign_count == 0)
		(*i)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	n = 0;
	i = 0;
	sign = 1;
	if (check_errors(nptr, &sign, &i) == 0)
		return (0);
	while (ft_isdigit(nptr[i]))
	{
		n *= 10;
		n += nptr[i] - '0';
		i++;
	}
	n *= sign;
	return (n);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	char test_1[] = "-+42";
	char test_2[] = "    42";
	char test_3[] = "0";
	char test_4[] = "2147483648";
	char test_5[] = "-2147483747";
	char test_6[] = "--42";
	char test_7[] = "-    42";
	char test_8[] = "4/---3";
	char test_9[] = "---45---";

	printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_1, ft_atoi(test_1), test_1, atoi(test_1));
	printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_2, ft_atoi(test_2), test_2, atoi(test_2));
	printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_3, ft_atoi(test_3), test_3, atoi(test_3));
	printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_4, ft_atoi(test_4), test_4, atoi(test_4));
	printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_5, ft_atoi(test_5), test_5, atoi(test_5));
			printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_6, ft_atoi(test_6), test_6, atoi(test_6));

printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_7, ft_atoi(test_7), test_7, atoi(test_7));
printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_8, ft_atoi(test_8), test_8, atoi(test_8));
printf("ft_atoi(%s) = %d\n   atoi(%s) = %d\n\n",
			test_9, ft_atoi(test_9), test_9, atoi(test_9));

	return (0);
}*/
