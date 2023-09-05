/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:27:40 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:27:45 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_CLASS_HPP__
# define __HUMANB_CLASS_HPP__

#include "Weapon.class.hpp"
#include <iostream>

class HumanB
{

private:
    Weapon _myWeapon;

public:
    HumanB(/* args */);
    ~HumanB();

};

#endif