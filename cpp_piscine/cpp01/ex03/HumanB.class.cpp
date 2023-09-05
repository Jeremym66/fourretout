/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:27:49 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:27:51 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.class.hpp"
#include "Weapon.class.hpp"

HumanB::HumanB(std::string name) : _myWeapon(NULL), _name(name)
{
    std::cout << "constructor HumanB His name is " << _name << std::endl;
    std::cout << this->_name;
    std::cout << ": I have no weapon !" << std::endl << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "destructor HumanB" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
    this->_myWeapon = &weapon;
    std::cout << this->_name;
    std::cout << ": My new Weapon is a " << _myWeapon->Weapon::getType() << std::endl << std::endl;
}

void    HumanB::Attack()
{
    if (_myWeapon == NULL)
    {
        std::cout << "!!! Warning !!! ------------  ";
        std::cout << this->_name << " punch attacks" << std::endl << std::endl;
    }
    else
    {
        std::cout << "!!! Warning !!! ------------  ";
        std::cout << this->_name << " attacks with his " << _myWeapon->Weapon::getType() << std::endl << std::endl;
    }
}