/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:10:14 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 16:32:24 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap(std::string namee) : ClapTrap(namee + "_clap_name")
{
    std::cout << "DiamondTrap " << namee << " constructor" << std::endl;
    std::cout << ">>>>>>    ";
    this->name = ClapTrap::name;
    std::cout << ">>>>>>    ";
    this->hitpts = FragTrap::hitpts;
    std::cout << ">>>>>>    ";
    this->Setenergy(100);
    std::cout << ">>>>>>    ";
    this->Setattackdmg(30);
    std::cout << std::endl;
    return;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->Getname() << " destructor" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & a) : ClapTrap()
{
    std::cout << "DiamondTrap Constructor copy" << std::endl;
    *this = a;
    return;    
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
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

void    DiamondTrap::highFivesGuys(void)
{
    std::cout << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "| Hey Guys !! Give me a high five !!    |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl << std::endl;
    return;
}

void DiamondTrap::attack(const std::string & target)
{
    if (this->Getenergy() > 0 && this->Gethit() > 0)
    {
        std::cout << "DiamondTrap " << this->Getname() << " attacks " << target << ", causing " << this->Getattackdmg() << " points of damage!" << std::endl;
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