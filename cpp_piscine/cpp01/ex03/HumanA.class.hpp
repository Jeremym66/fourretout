/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:27:31 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:27:33 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_CLASS_HPP__
# define __HUMANA_CLASS_HPP__

#include "Weapon.class.hpp"
#include <iostream>

class HumanA
{

private:
    const Weapon &_myWeapon;
    std::string _name;

public:
    HumanA(Weapon &my_weapon, std::string name);
    ~HumanA();

    void    Attack(void);

};

#endif
