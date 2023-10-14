/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:30:54 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 14:52:57 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.class.hpp"

class ScavTrap : public ClapTrap 
{
public :

    ScavTrap(std::string name);
    ~ScavTrap(void);
    ScavTrap(ScavTrap const & a);
    ScavTrap & operator=(ScavTrap const & rhs);

    void    guardGate();
    void    attack(const std::string & target);

private :

};