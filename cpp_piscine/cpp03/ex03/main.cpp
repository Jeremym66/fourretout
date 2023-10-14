/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:10:48 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 16:07:14 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"

int main()
{
    ClapTrap Robot1("Grincheux");
    ScavTrap Robot2("Timide");
    ScavTrap Robot3(Robot2);
    FragTrap Robot4("Joyeux");

    Robot3.Setname("Fofolle");
    Robot1.getAll();
    Robot2.getAll();
    
    Robot2.guardGate();
    Robot2.ScavTrap::attack("Fofolle");
    Robot3.takeDamage(Robot2.Getattackdmg());
    Robot2.ClapTrap::attack("Fofolle");
    Robot3.takeDamage(Robot2.Getattackdmg());

    Robot4.highFivesGuys();

    return (0);
}