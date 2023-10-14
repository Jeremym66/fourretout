/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:57:11 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 16:00:15 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap()
{
    std::cout << "FragTrap " << name << " constructor" << std::endl;
    std::cout << ">>>>>>    ";
    this->Setname(name);
    std::cout << ">>>>>>    ";
    this->Sethit(100);
    std::cout << ">>>>>>    ";
    this->Setenergy(100);
    std::cout << ">>>>>>    ";
    this->Setattackdmg(30);
    std::cout << std::endl;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->Getname() << " destructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const & a) : ClapTrap()
{
    std::cout << "FragTrap Constructor copy" << std::endl;
    *this = a;
    return;    
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
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

void    FragTrap::highFivesGuys(void)
{
    std::cout << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "| Hey Guys !! Give me a high five !!    |" << std::endl;
    std::cout << "-----------------------------------------" << std::endl << std::endl;
    return;
}

void FragTrap::attack(const std::string & target)
{
    if (this->Getenergy() > 0 && this->Gethit() > 0)
    {
        std::cout << "FragTrap " << this->Getname() << " attacks " << target << ", causing " << this->Getattackdmg() << " points of damage!" << std::endl;
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