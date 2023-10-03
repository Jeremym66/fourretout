/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/03 07:27:59 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int	main(void)
{
    int i;
    std::string name;

    std::cout << "Hello, today you have the power to create a horde of Zombies!!" << std::endl;
    std::cout << "So tell me how many Zombies do you want?? " << std::endl;
    std::cin >> i;
    std::cout << "Perfect, now give them a name... for exemple : Walkers ! " << std::endl;
    std::cin >> name;
    Zombie  *horde = zombieHorde((int)i , name);

    delete[] horde;
	return (0);
}