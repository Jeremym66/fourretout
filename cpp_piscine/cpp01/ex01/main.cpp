/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 09:00:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int	main(void)
{
    int i;
    std::string name;

    std::cout << "Hello, today you have the power to create a horde of Zombies!!" << std::endl;
    std::cout << "So tell me how many Zombies do you want?? ";
    std::cin >> i;
    std::cout << "Perfect, now give them a name... ";
    std::cin >> name;
    Zombie  *horde = zombieHorde((int)i , name);

    delete[] horde;
	return (0);
}