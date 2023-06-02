/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:56:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/06/02 17:42:07 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	get_digit(char c, int digits_in_base)
{
	int max_digit;
	
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';
    	if (c >= '0' && c <= '9' && c <= max_digit)
        	return (c - '0');
    	else if (c >= 'a' && c <= 'f' && c <= max_digit)
        	return (10 + c - 'a');
    	else
        	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base + digit;
		++str;
	}
	return (result * sign);
}
/*
#include <stdio.h>

int      main(void)
{
	printf("%d\n", ft_atoi_base("15690b80Be", 16));
	printf("%d\n", ft_atoi_base("0", 16));
	printf("%d\n", ft_atoi_base("1", 16));
	printf("%d\n", ft_atoi_base("-111", 16));
}*/
