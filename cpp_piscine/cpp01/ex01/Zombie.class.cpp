/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 09:00:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"


Zombie::Zombie(void)
{
    // std::cout << "Zombie is born" << std::endl;
    return;
}

// Zombie::Zombie(std::string name) : _name(name)
// {
//     std::cout << "Zombie " << _name << " is born" << std::endl;
//     Zombie::announce();
//     return;
// }

Zombie::~Zombie(void)
{
    return;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

void    Zombie::setname(std::string name, int i)
{
    _name = name + std::to_string(i);
    Zombie::announce();
    return;
}