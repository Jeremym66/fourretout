/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:18:06 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/13 18:19:48 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

//      constructor & destructor     //

ClapTrap::ClapTrap(std::string name) : _hitpts(10), _energypts(10), _attackdmg(0), _name(name)
{
    std::cout << "Clap " << this->_name << " Constructor" << std::endl;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Clap " << this->_name << " Destructor" << std::endl;
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
        this->_hitpts = rhs.Gethit();
        this->_energypts = rhs.Getenergy();
        this->_attackdmg = rhs.Getattackdmg();
        this->_name = rhs.Getname();
    }
    return(*this);
}

//      Set or get      //

void    ClapTrap::Sethit(int const raw)
{
    this->_hitpts = raw;
    std::cout << "Hit points of " << this->_name << " now is : " << this->Gethit() << std::endl;
    return;
}

void    ClapTrap::Setenergy(int const raw)
{
    this->_energypts = raw;
    std::cout << "Energy of " << this->_name << " now is : " << this->Getenergy() << std::endl;
    return;
}

void    ClapTrap::Setattackdmg(int const raw)
{
    this->_attackdmg = raw;
    std::cout << "Attack damage of " << this->_name << " now is : " << this->Getattackdmg() << std::endl;
    return;
}

int ClapTrap::Gethit(void) const
{
    return (this->_hitpts);
}

int ClapTrap::Getenergy(void) const
{
    return (this->_energypts);
}

int ClapTrap::Getattackdmg(void) const
{
    return (this->_attackdmg);
}

std::string ClapTrap::Getname(void) const
{
    return (this->_name);
}

//      Others      //

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitpts <= 0)
    {
        std::cout << this->_name << " is already died !!" << std::endl;
        return;
    }
    std::cout << this->_name << " takes damages ( " << amount << " pts ) !!" << std::endl;
    this->_hitpts -= amount;
    if (this->_hitpts > 0)
        std::cout << "New Hitpts : " << this->Gethit() << std::endl;
    else
        std::cout << this->_name <<" is died !! RIP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energypts > 0 && this->_hitpts > 0)
    {
        std::cout << this->_name << " be repaired ( " << amount << " pts ) !!" << std::endl;
        this->_hitpts += amount;
        std::cout << "New Hitpts : " << this->Gethit() << std::endl;
        this->_energypts--;
    }
    else
    {
        if (this->_energypts <= 0)
            std::cout << this->_name << " is out of energy !! You cant repair it !" << std::endl;
        else
            std::cout << this->_name << " is died !! You cant repair it !" << std::endl;
    }
    return;
}

void ClapTrap::attack(const std::string & target)
{
    if (this->_energypts > 0 && this->_hitpts > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->Getattackdmg() << " points of damage!" << std::endl;
        this->_energypts--;
    }
    else
    {
        if (this->_energypts <= 0)
            std::cout << this->_name << " cant attack he is out of energy !" << std::endl;
        else
            std::cout << this->_name << " is died !! You cant attack with it !" << std::endl;
    }
}

void ClapTrap::getAll(void)
{
    std::cout << "Robot : " << this->Getname() << std::endl;
    std::cout << "life : " << this->Gethit() << std::endl;
    std::cout << "Energy : " << this->Getenergy() << std::endl;
    std::cout << "Attack Damage : " << this->Getattackdmg() << std::endl << std::endl;
}

