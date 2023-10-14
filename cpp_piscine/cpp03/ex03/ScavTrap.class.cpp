/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:30:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 15:24:26 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
    std::cout << "ScavTrap " << name << " constructor" << std::endl;
    std::cout << ">>>>>>    ";
    this->Setname(name);
    std::cout << ">>>>>>    ";
    this->Sethit(100);
    std::cout << ">>>>>>    ";
    this->Setenergy(50);
    std::cout << ">>>>>>    ";
    this->Setattackdmg(20);
    std::cout << std::endl;
    return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->Getname() << " destructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & a) : ClapTrap()
{
    std::cout << "ScavTrap Constructor copy" << std::endl;
    *this = a;
    return;    
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
    if (this != &rhs)
    {
        std::cout << "******    ";
        this->Setname(rhs.Getname());
        std::cout << "******    ";
        this->Sethit(rhs.Gethit());
        std::cout << "******    ";
        this->Setenergy(rhs.Getenergy());
        std::cout << "******    ";
        this->Setattackdmg(rhs.Getattackdmg());
        std::cout << std::endl;
    }
    return(*this);
}

void    ScavTrap::guardGate()
{
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "| " << this->Getname() << " is in Gate Keeper's mode !!!   |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl << std::endl;
    return;
}

void ScavTrap::attack(const std::string & target)
{
    if (this->Getenergy() > 0 && this->Gethit() > 0)
    {
        std::cout << "ScavTrap " << this->Getname() << " attacks " << target << ", causing " << this->Getattackdmg() << " points of damage!" << std::endl;
        this->Setenergy(this->Getenergy() - 1);
    }
    else
    {
        if (this->Getenergy() <= 0)
            std::cout << this->Getname() << " cant attack he is out of energy !" << std::endl;
        else
            std::cout << this->Getname() << " is died !! You cant attack with it !" << std::endl;
    }
}