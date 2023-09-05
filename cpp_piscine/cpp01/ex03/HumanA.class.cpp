/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:27:21 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:27:24 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.class.hpp"

HumanA::HumanA(std::string myWeapon)
{
    std::cout << "constructor HumanA" << std::endl;
    std::cout << "my weapon is : " << myWeapon << std::endl;
    // std::cout << "my weapon is : " << Weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "destructor HumanA" << std::endl;
}




