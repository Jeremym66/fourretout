/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:27:21 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:27:24 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.class.hpp"
#include "Weapon.class.hpp"

HumanA::HumanA(Weapon &myWeapon, std::string name) : _myWeapon(myWeapon), _name(name)
{
    std::cout << "constructor HumanA His name is " << _name << std::endl;
    std::cout << this->_name;
    std::cout << ": My weapon is a " << myWeapon.getType() << std::endl << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "destructor HumanA" << std::endl;
}

void    HumanA::Attack()
{
    std::cout << "!!! Warning !!! ------------  ";
    std::cout << this->_name << " attacks with his " << _myWeapon.Weapon::getType() << std::endl << std::endl;
}