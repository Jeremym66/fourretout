/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:28:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/05 07:28:32 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"

int main()
{
    Weapon  Revolver("Revolver");
    Weapon  Crossbow("Crossbow");
    Weapon  Knife("Knife");

    HumanA  Rick(Revolver, "Rick");
    Rick.Attack();
    Revolver.setType("Gold Revolver");
    Rick.Attack();

    
    HumanB  Daryl("Daryl");
    Daryl.Attack();

    Daryl.setWeapon(Crossbow);
    Daryl.Attack();
    Crossbow.setType("Gold Crossbow");
    Daryl.Attack();

    Daryl.setWeapon(Knife);
    Daryl.Attack();
    Knife.setType("Gold knife");
    Daryl.Attack();
    
    return (0);
}
