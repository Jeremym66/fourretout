/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:12:12 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/13 18:01:11 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {

public :

    ClapTrap(std::string name);
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

    void attack(const std::string & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void getAll(void);

private :

    int _hitpts;
    int _energypts;
    int _attackdmg;
    std::string _name;

};