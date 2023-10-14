/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:18:06 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 16:23:20 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

//      constructor & destructor     //

ClapTrap::ClapTrap(void)
{
    std::cout << "Basic Clap Constructor" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string namee) : hitpts(10), energypts(10), attackdmg(0), name(namee)
{
    std::cout << "Clap " << this->name << " Constructor" << std::endl;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Clap " << this->name << " Destructor" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "Clap Constructor copy" << std::endl;
    *this = src;
    return;
}

//      operator        //

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    if (this != &rhs)
    {
        this->hitpts = rhs.Gethit();
        this->energypts = rhs.Getenergy();
        this->attackdmg = rhs.Getattackdmg();
        this->name = rhs.Getname();
    }
    return(*this);
}

//      Set or get      //

void    ClapTrap::Sethit(int const raw)
{
    this->hitpts = raw;
    std::cout << "Hit points of " << this->Getname() << " is now : " << this->Gethit() << std::endl;
    return;
}

void    ClapTrap::Setenergy(int const raw)
{
    this->energypts = raw;
    std::cout << "Energy of " << this->Getname() << " is now : " << this->Getenergy() << std::endl;
    return;
}

void    ClapTrap::Setattackdmg(int const raw)
{
    this->attackdmg = raw;
    std::cout << "Attack damage of " << this->Getname() << " is now : " << this->Getattackdmg() << std::endl;
    return;
}

void    ClapTrap::Setname(std::string name)
{
    if (this->Getname() != "")
        std::cout << this->Getname() <<" is now called : " << name << std::endl;
    else
        std::cout << "The name is now : " << name << std::endl;
    this->name = name;
    return;
}

int ClapTrap::Gethit(void) const
{
    return (this->hitpts);
}

int ClapTrap::Getenergy(void) const
{
    return (this->energypts);
}

int ClapTrap::Getattackdmg(void) const
{
    return (this->attackdmg);
}

std::string ClapTrap::Getname(void) const
{
    return (this->name);
}

//      Others      //

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitpts <= 0)
    {
        std::cout << this->name << " is already died !!" << std::endl;
        return;
    }
    std::cout << this->name << " takes damages ( " << amount << " pts ) !!" << std::endl;
    this->hitpts -= amount;
    if (this->hitpts > 0)
        std::cout << "New Hitpts : " << this->Gethit() << std::endl;
    else
        std::cout << this->name <<" is died !! RIP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energypts > 0 && this->hitpts > 0)
    {
        std::cout << this->name << " be repaired ( " << amount << " pts ) !!" << std::endl;
        this->hitpts += amount;
        std::cout << "New Hitpts : " << this->Gethit() << std::endl;
        this->energypts--;
    }
    else
    {
        if (this->energypts <= 0)
            std::cout << this->name << " is out of energy !! You cant repair it !" << std::endl;
        else
            std::cout << this->name << " is died !! You cant repair it !" << std::endl;
    }
    return;
}

void ClapTrap::attack(const std::string & target)
{
    if (this->energypts > 0 && this->hitpts > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->Getattackdmg() << " points of damage!" << std::endl;
        this->energypts--;
        std::cout << "Energy of " << this->Getname() << " is now : " << this->Getenergy() << std::endl;
    }
    else
    {
        if (this->energypts <= 0)
            std::cout << this->name << " cant attack he is out of energy !" << std::endl;
        else
            std::cout << this->name << " is died !! You cant attack with it !" << std::endl;
    }
}

void ClapTrap::getAll(void)
{
    std::cout << "Robot : " << this->Getname() << std::endl;
    std::cout << "  life : " << this->Gethit() << std::endl;
    std::cout << "  Energy : " << this->Getenergy() << std::endl;
    std::cout << "  Attack Damage : " << this->Getattackdmg() << std::endl << std::endl;
}

