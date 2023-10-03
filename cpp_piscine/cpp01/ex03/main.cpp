/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:28:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/03 08:55:48 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"

/*int main()
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
}*/

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob(club, "bob");
        bob.Attack();
        club.setType("some other type of club");
        bob.Attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.Attack();
        club.setType("some other type of club");
        jim.Attack();
    }
return 0;
}