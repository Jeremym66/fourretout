/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/08/31 17:01:20 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*ft_toupper(char *str)
{
	int	i;
	char	*temp;
	i = -1;

	temp = str;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			temp[i] = str[i] - 32;
		else
			temp[i] = str[i];
	}
	return (temp);
}

int	main(int ac, char **av)
{
	int	i;
	char	*temp;

	i = 0;
	if ( ac < 2 )
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while(av[++i])
		{
			temp = ft_toupper(av[i]);
			std::cout << temp;
		}
		std::cout << std::endl;
	}
	return 0;
}
