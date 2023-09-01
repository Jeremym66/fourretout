/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 08:00:15 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "megaphone.class.hpp"

int	main(int ac, char **av)
{
	Megaphone instance;
	int	i;

	i = 0;
	if ( ac < 2 )
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		while(++i < ac)
			instance.up(av[i]);
	std::cout << std::endl;
	return 0;
}
