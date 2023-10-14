/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:12:12 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 16:32:26 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {

public :

    ClapTrap(std::string namee);
    ClapTrap(void);
    ~ClapTrap(void);
    ClapTrap(ClapTrap const & src);
    ClapTrap & operator=(ClapTrap const & rhs);

    int Gethit(void) const;
    int Getenergy(void) const;
    int Getattackdmg(void) const;
    std::string Getname(void) const;
    void    Sethit(int const raw);
    void    Setenergy(int const raw);
    void    Setattackdmg(int const raw);
    void    Setname(std::string name);

    void attack(const std::string & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void getAll(void);

protected :

    int hitpts;
    int energypts;
    int attackdmg;
    std::string name;

};